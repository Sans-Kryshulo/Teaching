#ifndef STACK_H
#define STACK_H

class Stack {
private:
    char* data;
    int size;
    int capacity;

public:
    Stack();
    Stack(const Stack& other) = delete;
    Stack(Stack&& other) noexcept;
    ~Stack();

    Stack& operator=(const Stack& other) = delete;
    Stack& operator=(Stack&& other) noexcept;

    bool isEmpty() const;
    void push(char value);
    char pop();
};

#endif

