#ifndef NODE_H
#define NODE_H

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

#endif 
