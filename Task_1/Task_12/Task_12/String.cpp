#include "string.h"

String::String() : data(new char[defaultSize]), size(defaultSize) {}

String::String(int size) : data(new char[size]), size(size) {}

String::String(const char* str) : data(nullptr), size(0) {
    int len = strlen(str) + 1;
    data = new char[len];
    size = len;
    strcpy_s(data, len, str);
}

String::~String() {
    delete[] data;
}

void String::input() {
    std::cout << "Введите текст:";
    std::cin.getline(data, size);
}

void String::output() const {
    std::cout << "Текст: " << data << std::endl;
}