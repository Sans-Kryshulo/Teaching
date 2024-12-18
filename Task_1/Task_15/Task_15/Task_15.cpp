#include <iostream>
#include <sstream>
#include "String.h"
#include "String.h"
#include "Array.h"

int getUserInput() {
    while (true) {
        std::string input;
        std::cin >> input;
        std::cin.ignore();
        std::stringstream stream(input);
        int result;
        if (stream >> result && stream.eof()) {
            return result;
        }
        else {
            std::cout << "Ошибка! Введено некоректное значения. Спробуйте ёще раз: ";
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int usernum;
    bool ExitBool = false;
    while (ExitBool == false)
    {
        bool open = false;
        bool exit = false;
        usernum = 0;
        std::cout << "Введите целое число от 1 до 2: ";
        while (open == false)
        {
            usernum = getUserInput();
            if (usernum == 1) {
                String s1("Hello");
                std::cout << "Initial string: " << s1 << std::endl;
                std::cout << "Character at index 2: " << s1[2] << std::endl;
                char searchChar = 'l';
                int index = s1(searchChar);
                if (index != -1) {
                    std::cout << "Character '" << searchChar << "' found at index: " << index << std::endl;
                }
                else {
                    std::cout << "Character '" << searchChar << "' not found." << std::endl;
                }
                int len = static_cast<int>(s1);
                std::cout << "Length of string: " << len << std::endl;
                ++s1;
                std::cout << "After increment: " << s1 << std::endl;
                --s1;
                std::cout << "After decrement: " << s1 << std::endl;

                open = true;
            }
            else if (usernum == 2) {
                Array arr1(5);
                std::cout << "Array 1: " << arr1 << std::endl;

                Array arr2 = arr1;
                std::cout << "Array 2 (copied from Array 1): " << arr2 << std::endl;

                Array arr3(5);
                std::cout << "Array 3: " << arr3 << std::endl;

                arr3 = std::move(arr2);
                std::cout << "Array 3 (moved from Array 2): " << arr3 << std::endl;

                Array arr4 = 5 + arr1;
                std::cout << "Array 4 (5 + Array 1): " << arr4 << std::endl;

                open = true;
            }
            else {
                std::cout << "Введенное значение не в диапазоне. Спробуйте ёще раз: ";
                open = false;
            }
        }
        std::cout << "Продолжить роботу програми? (Y/N)\n";
        while (exit == false)
        {
            std::string userexit;
            std::cin >> userexit;
            if (userexit == "n" || userexit == "N") {
                ExitBool = true;
                exit = true;
            }
            else if (userexit == "y" || userexit == "Y") {
                ExitBool = false;
                exit = true;
            }
            else {
                ExitBool = false;
                exit = false;
                std::cout << "Введено некоректное значения. Спробуйте ёще раз. \n";
            }
        }
    }
}
