#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack {
public:
    Stack();
    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;
    Stack& operator=(const Stack& other);
    Stack& operator=(Stack&& other) noexcept;
    ~Stack();

    void push(int value);
    int pop();
    int peek() const;
    bool isEmpty() const;

private:
    Node* head;
    void clear();
    void copyFrom(const Stack& other);
};

#endif
