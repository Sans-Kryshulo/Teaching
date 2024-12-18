#include "Stack.h"
#include <stdexcept>

Stack::Stack() : head(nullptr) {}

Stack::Stack(const Stack& other) : head(nullptr) {
    copyFrom(other);
}

Stack::Stack(Stack&& other) noexcept : head(other.head) {
    other.head = nullptr;
}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

Stack& Stack::operator=(Stack&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

Stack::~Stack() {
    clear();
}

void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    Node* temp = head;
    int value = head->data;
    head = head->next;
    delete temp;
    return value;
}

int Stack::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return head->data;
}

bool Stack::isEmpty() const {
    return head == nullptr;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::copyFrom(const Stack& other) {
    if (other.head == nullptr) {
        return;
    }

    head = new Node(other.head->data);
    Node* current = head;
    Node* otherCurrent = other.head->next;

    while (otherCurrent != nullptr) {
        current->next = new Node(otherCurrent->data);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}
