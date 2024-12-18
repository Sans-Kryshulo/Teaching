#include "Array.h"

Array::Array(int size) : data(new int[size]), size(size) {
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

Array::Array(const Array& other) : data(new int[other.size]), size(other.size) {
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Array::Array(Array&& other) noexcept : data(nullptr), size(0) {
    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
}

Array::~Array() {
    delete[] data;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;

        data = new int[other.size];
        size = other.size;
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] data;

        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

Array operator+(int value, const Array& arr) {
    Array result(arr.size);
    for (int i = 0; i < arr.size; ++i) {
        result.data[i] = value + arr.data[i];
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Array& arr) {
    os << "[";
    for (int i = 0; i < arr.size; ++i) {
        os << arr.data[i];
        if (i != arr.size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
