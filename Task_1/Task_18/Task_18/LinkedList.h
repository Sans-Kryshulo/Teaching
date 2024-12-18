#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList(LinkedList&& other) noexcept;
    LinkedList& operator=(const LinkedList& other);
    LinkedList& operator=(LinkedList&& other) noexcept;
    ~LinkedList();

    void push(int value);
    int pop();
    int peek() const;
    bool isEmpty() const;
    Node* clone() const;

    LinkedList operator+(const LinkedList& other) const;
    LinkedList operator*(const LinkedList& other) const;

private:
    Node* head;
    void clear();
    void copyFrom(const LinkedList& other);
};

#endif
