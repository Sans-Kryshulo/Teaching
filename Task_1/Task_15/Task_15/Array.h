#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
private:
    int* data;
    int size;

public:
    Array(int size);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array();

    Array& operator=(const Array& other); 
    Array& operator=(Array&& other) noexcept;

    friend Array operator+(int value, const Array& arr);
    friend std::ostream& operator<<(std::ostream& os, const Array& arr);

};

#endif