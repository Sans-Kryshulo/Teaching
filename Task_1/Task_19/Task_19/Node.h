#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

#endif 