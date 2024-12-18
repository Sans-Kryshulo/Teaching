#include "Stack.h"
#ifndef BRACKET_CHECKER_H
#define BRACKET_CHECKER_H

class BracketChecker {
private:
    Stack stack;

public:
    BracketChecker() = default;
    BracketChecker(const BracketChecker& other) = delete;
    BracketChecker(BracketChecker&& other) noexcept = default;
    ~BracketChecker() = default;

    BracketChecker& operator=(const BracketChecker& other) = delete;
    BracketChecker& operator=(BracketChecker&& other) noexcept = default;

    bool check(const char* str);
};

#endif
