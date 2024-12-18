#include "String.h"
#include <cstring>
#include <stdexcept>

String::String() : str(nullptr), length(0) {}

String::String(const char* s) : str(nullptr), length(0) {
    if (s != nullptr) {
        length = static_cast<int>(std::strlen(s));
        str = new char[length + 1];
        strcpy_s(str, length + 1, s);
    }
}

String::~String() {
    delete[] str;
}

char& String::operator[](int index) {
    if (index >= 0 && index < length) {
        return str[index];
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

int String::operator()(char c) const {
    for (int i = 0; i < length; ++i) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}

String::operator int() const {
    return length;
}

String& String::operator++() {
    char* newStr = new char[length + 2];
    strcpy_s(newStr, length + 2, str);
    newStr[length] = ' ';
    newStr[length + 1] = '\0';
    delete[] str;
    str = newStr;
    ++length;
    return *this;
}

String& String::operator--() {
    if (length > 0) {
        char* newStr = new char[length];
        strncpy_s(newStr, length, str, length - 1);
        newStr[length - 1] = '\0';
        delete[] str;
        str = newStr;
        --length;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const String& s) {
    if (s.str != nullptr) {
        os << s.str;
    }
    return os;
}

