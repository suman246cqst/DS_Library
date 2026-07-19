#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template<typename T>
class Queue{
private:
    LinkedList<T> ll;

public:
    void enqueue(const T& val);
    T dequeue();
    int size() const;
    bool isEmpty() const;
    const T& peek();
};

#include "../src/queue.cpp"

#endif