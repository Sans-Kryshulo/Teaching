#include "LinkedList.h"
#include <stdexcept>
#include <unordered_set>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(const LinkedList& other) : head(nullptr) {
    copyFrom(other);
}

LinkedList::LinkedList(LinkedList&& other) noexcept : head(other.head) {
    other.head = nullptr;
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

int LinkedList::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    Node* temp = head;
    int value = head->data;
    head = head->next;
    delete temp;
    return value;
}

int LinkedList::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return head->data;
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

Node* LinkedList::clone() const {
    if (!head) return nullptr;

    Node* newHead = new Node(head->data);
    Node* currentNew = newHead;
    Node* currentOld = head->next;

    while (currentOld) {
        currentNew->next = new Node(currentOld->data);
        currentNew = currentNew->next;
        currentOld = currentOld->next;
    }
    return newHead;
}

LinkedList LinkedList::operator+(const LinkedList& other) const {
    LinkedList result;

    Node* current = head;
    while (current) {
        result.push(current->data);
        current = current->next;
    }

    current = other.head;
    while (current) {
        result.push(current->data);
        current = current->next;
    }

    LinkedList reversedResult;
    while (!result.isEmpty()) {
        reversedResult.push(result.pop());
    }

    return reversedResult;
}

LinkedList LinkedList::operator*(const LinkedList& other) const {
    LinkedList result;
    std::unordered_set<int> elements;

    Node* current = head;
    while (current) {
        elements.insert(current->data);
        current = current->next;
    }

    current = other.head;
    while (current) {
        if (elements.find(current->data) != elements.end()) {
            result.push(current->data);
        }
        current = current->next;
    }

    LinkedList reversedResult;
    while (!result.isEmpty()) {
        reversedResult.push(result.pop());
    }

    return reversedResult;
}

void LinkedList::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void LinkedList::copyFrom(const LinkedList& other) {
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
