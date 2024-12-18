#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
private:
    char* str;
    int length;

public:
    String();
    String(const char* s);
    ~String();

    char& operator[](int index);
    int operator()(char c) const;
    operator int() const;
    String& operator++();
    String& operator--();

    friend std::ostream& operator<<(std::ostream& os, const String& s);
};

#endif
