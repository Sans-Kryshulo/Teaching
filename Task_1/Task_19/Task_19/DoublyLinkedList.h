#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <stdexcept>

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void pushBack(T value);
    void popFront();
    T front() const;
    bool isEmpty() const;

    DoublyLinkedList<T> clone() const;
    DoublyLinkedList<T> operator+(const DoublyLinkedList<T>& other) const;
    DoublyLinkedList<T> operator*(const DoublyLinkedList<T>& other) const;

    void printList() const;

private:
    Node<T>* head;
    Node<T>* tail;

    void pushBackNode(Node<T>* node);
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (!isEmpty()) {
        popFront();
    }
}

template <typename T>
void DoublyLinkedList<T>::pushBack(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (tail) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else {
        head = tail = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::popFront() {
    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }
    Node<T>* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
}

template <typename T>
T DoublyLinkedList<T>::front() const {
    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }
    return head->data;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void DoublyLinkedList<T>::pushBackNode(Node<T>* node) {
    if (tail) {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    else {
        head = tail = node;
    }
}

template <typename T>
DoublyLinkedList<T> DoublyLinkedList<T>::clone() const {
    DoublyLinkedList<T> newList;
    Node<T>* current = head;
    while (current) {
        newList.pushBack(current->data);
        current = current->next;
    }
    return newList;
}

template <typename T>
DoublyLinkedList<T> DoublyLinkedList<T>::operator+(const DoublyLinkedList<T>& other) const {
    DoublyLinkedList<T> newList = this->clone();
    Node<T>* current = other.head;
    while (current) {
        newList.pushBack(current->data);
        current = current->next;
    }
    return newList;
}

template <typename T>
DoublyLinkedList<T> DoublyLinkedList<T>::operator*(const DoublyLinkedList<T>& other) const {
    DoublyLinkedList<T> newList;
    Node<T>* currentA = this->head;
    while (currentA) {
        Node<T>* currentB = other.head;
        while (currentB) {
            if (currentA->data == currentB->data) {
                newList.pushBack(currentA->data);
                break;
            }
            currentB = currentB->next;
        }
        currentA = currentA->next;
    }
    return newList;
}

template <typename T>
void DoublyLinkedList<T>::printList() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif
