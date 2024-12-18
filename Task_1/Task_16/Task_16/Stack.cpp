#include "Stack.h"
#include <iostream>

Stack::Stack() : data(nullptr), size(0), capacity(0) {}

Stack::Stack(Stack&& other) noexcept : data(nullptr), size(0), capacity(0) {
    data = other.data;
    size = other.size;
    capacity = other.capacity;
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

Stack::~Stack() {
    delete[] data;
}

Stack& Stack::operator=(Stack&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

bool Stack::isEmpty() const {
    return size == 0;
}

void Stack::push(char value) {
    if (size == capacity) {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        char* newData = new char[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = value;
}

char Stack::pop() {
    if (!isEmpty()) {
        return data[--size];
    }
    std::cerr << "Error: popping from an empty stack\n";
    return '\0';
}
