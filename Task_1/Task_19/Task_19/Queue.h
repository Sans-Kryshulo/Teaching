#ifndef QUEUE_H
#define QUEUE_H

#include "DoublyLinkedList.h"

template <typename T>
class Queue {
public:
    Queue();
    void enqueue(T value);
    void dequeue();
    T front() const;
    bool isEmpty() const;

private:
    DoublyLinkedList<T> list;
};

template <typename T>
Queue<T>::Queue() {}

template <typename T>
void Queue<T>::enqueue(T value) {
    list.pushBack(value);
}

template <typename T>
void Queue<T>::dequeue() {
    list.popFront();
}

template <typename T>
T Queue<T>::front() const {
    return list.front();
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return list.isEmpty();
}

#endif
