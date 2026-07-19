#include "../include/queue.h"
using namespace std; 

template<typename T>
void Queue<T>::enqueue(const T& val){
    ll.push_back(val);
}

template<typename T>
T Queue<T>::dequeue(){
    if (ll.getSize() == 0){
        throw std::underflow_error("Queue is empty");
    }
    Node<T>* temp=ll.getHead();
    T nodeData=temp->data;
    ll.pop_front();
    return nodeData;
}

template<typename T>
int Queue<T>::size() const{
    return ll.getSize();
}

template<typename T>
bool Queue<T>::isEmpty() const{
    return ll.getSize() == 0;
}

template<typename T>
const T& Queue<T>::peek(){
    if (ll.getSize() == 0){
        throw std::out_of_range("Queue is empty");
    }
    return ll.get(0);
}