#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>

template <typename T>
class Array {
public:
    Array();
    ~Array();

    int GetSize() const;
    void SetSize(int size, int grow = 1);
    int GetUpperBound() const;
    bool IsEmpty() const;
    void FreeExtra();
    void RemoveAll();
    T GetAt(int index) const;
    void SetAt(int index, const T& value);
    T& operator[](int index);
    const T& operator[](int index) const;
    void Add(const T& value);
    Array<T> Append(const Array<T>& other) const;
    Array<T>& operator=(const Array<T>& other);
    T* GetData();
    void InsertAt(int index, const T& value);
    void RemoveAt(int index);

private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;
    int grow;

    void AllocateMore();
};

template <typename T>
Array<T>::Array() : head(nullptr), tail(nullptr), size(0), grow(1) {}

template <typename T>
Array<T>::~Array() {
    RemoveAll();
}

template <typename T>
int Array<T>::GetSize() const {
    return size;
}

template <typename T>
void Array<T>::SetSize(int size, int grow) {
    if (size < 0 || grow <= 0) {
        throw std::invalid_argument("Invalid size or grow value");
    }

    this->grow = grow;
    if (size > this->size) {
        while (this->size < size) {
            AllocateMore();
        }
    }
    else if (size < this->size) {
        Node* current = head;
        while (size < this->size) {
            current = current->next;
            delete current->prev;
            --this->size;
        }
        head = current;
    }
}

template <typename T>
int Array<T>::GetUpperBound() const {
    return size - 1;
}

template <typename T>
bool Array<T>::IsEmpty() const {
    return size == 0;
}

template <typename T>
void Array<T>::FreeExtra() {
    SetSize(size);
}

template <typename T>
void Array<T>::RemoveAll() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

template <typename T>
T Array<T>::GetAt(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
void Array<T>::SetAt(int index, const T& value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    current->data = value;
}

template <typename T>
T& Array<T>::operator[](int index) {
    return const_cast<T&>(static_cast<const Array*>(this)->operator[](index));
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    return GetAt(index);
}

template <typename T>
void Array<T>::Add(const T& value) {
    if (!tail) {
        head = tail = new Node(value);
    }
    else {
        tail->next = new Node(value);
        tail->next->prev = tail;
        tail = tail->next;
    }
    ++size;
}

template <typename T>
Array<T> Array<T>::Append(const Array<T>& other) const {
    Array<T> result = *this;
    Node* current = other.head;
    while (current) {
        result.Add(current->data);
        current = current->next;
    }
    return result;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this == &other) {
        return *this;
    }
    RemoveAll();
    Node* current = other.head;
    while (current) {
        Add(current->data);
        current = current->next;
    }
    return *this;
}

template <typename T>
T* Array<T>::GetData() {
    T* data = new T[size];
    Node* current = head;
    for (int i = 0; i < size; ++i) {
        data[i] = current->data;
        current = current->next;
    }
    return data;
}

template <typename T>
void Array<T>::InsertAt(int index, const T& value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        Node* newNode = new Node(value);
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        else {
            tail
                = newNode;
        }
        head = newNode;
        if (!tail) {
            tail = newNode;
        }
    }
    else if (index == size) {
        Add(value);
    }
    else {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        Node* newNode = new Node(value);
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        ++size;
    }
}

template <typename T>
void Array<T>::RemoveAt(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }
    else if (index == size - 1) {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    else {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
    --size;
}

#endif
