#pragma once
#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <iostream>

class String {
private:
    static const int defaultSize = 80;
    char* data;
    int size;

public:
    String();
    String(int size);
    String(const char* str);
    ~String();

    void input();
    void output() const;
};

#endif // STRING_H