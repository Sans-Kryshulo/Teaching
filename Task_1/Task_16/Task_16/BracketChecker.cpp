#include "BracketChecker.h"
#include <iostream>

bool BracketChecker::check(const char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.isEmpty()) {
                std::cerr << "Error: closing bracket without corresponding opening bracket\n";
                return false;
            }
            char openBracket = stack.pop();
            if ((ch == ')' && openBracket != '(') ||
                (ch == ']' && openBracket != '[') ||
                (ch == '}' && openBracket != '{')) {
                std::cerr << "Error: mismatched opening and closing brackets\n";
                return false;
            }
        }
    }
    if (!stack.isEmpty()) {
        std::cerr << "Error: unclosed opening bracket\n";
        return false;
    }
    std::cout << "The string has correct bracket placement\n";
    return true;
}
