#include "linkedList.h"
using namespace std;

template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->next;
        temp->data.~T(); 
        free(temp);
    }
    head = nullptr;
    size = 0;
}
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    head = nullptr;
    size = 0;

    Node<T>* temp = other.head;
    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }
}
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this == &other) {
        return *this;
    }
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->next;
        temp->data.~T();
        free(temp);
    }
    head = nullptr;
    size = 0;
    Node<T>* temp = other.head;
    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }
    return *this;
}
template<typename T>
void LinkedList<T>::push_front(const T& val) {
    Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
    if (newNode == nullptr) {
        throw bad_alloc();
    }
    new (&newNode->data) T(val);
    newNode->next = head;
    head = newNode;
    size++;
}
template<typename T>
void LinkedList<T>::push_back(const T& val) {
    Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
    if (newNode == nullptr) {
        throw bad_alloc();
    }
    new (&newNode->data) T(val);
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        size++;
        return;
    }
    Node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    size++;
}
template<typename T>
void LinkedList<T>::pop_front() {
    if (head == nullptr) {
        throw underflow_error("List is empty");
    }
    Node<T>* temp = head;
    head = head->next;
    temp->data.~T();
    free(temp);
    size--;
}
template<typename T>
void LinkedList<T>::pop_back() {
    if (head == nullptr) {
        throw underflow_error("List is empty");
    }
    if (head->next == nullptr) {
        head->data.~T();
        free(head);
        head = nullptr;
        size--;
        return;
    }
    Node<T>* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    Node<T>* last = temp->next;
    temp->next = nullptr;
    last->data.~T();
    free(last);
    size--;
}
