#include <iostream>
#include <sstream>
#include "Fraction.h"
#include "Complex.h"
#include "Overcoat.h"
#include "Flat.h"

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

int main() {
    setlocale(LC_ALL, "Russian");
    int usernum;
    bool ExitBool = false;
    while (ExitBool == false)
    {
        bool open = false;
        bool exit = false;
        usernum = 0;
        std::cout << "Введите целое число от 1 до 4: ";
        while (open == false)
        {
            usernum = getUserInput();
            if (usernum == 1) {
                Fraction frac1(1, 2);
                Fraction frac2(3, 4);

                Fraction result_add = frac1 + frac2;
                Fraction result_sub = frac1 - frac2;
                Fraction result_mul = frac1 * frac2;
                Fraction result_div = frac1 / frac2;

                frac1.print();
                std::cout << " + ";
                frac2.print();
                std::cout << " = ";
                result_add.print();
                std::cout << std::endl;

                frac1.print();
                std::cout << " - ";
                frac2.print();
                std::cout << " = ";
                result_sub.print();
                std::cout << std::endl;

                frac1.print();
                std::cout << " * ";
                frac2.print();
                std::cout << " = ";
                result_mul.print();
                std::cout << std::endl;

                frac1.print();
                std::cout << " / ";
                frac2.print();
                std::cout << " = ";
                result_div.print();
                std::cout << std::endl;

                open = true;
            }
            else if (usernum == 2) {
                Complex c1(2.0, 3.0);
                Complex c2(1.0, -2.0);

                Complex sum = c1 + c2;
                Complex difference = c1 - c2;
                Complex product = c1 * c2;
                Complex quotient = c1 / c2;

                std::cout << "c1 = " << c1 << std::endl;
                std::cout << "c2 = " << c2 << std::endl;
                std::cout << "Sum: " << sum << std::endl;
                std::cout << "Difference: " << difference << std::endl;
                std::cout << "Product: " << product << std::endl;
                std::cout << "Quotient: " << quotient << std::endl;

                open = true;
            }
            else if (usernum == 3) {
                Overcoat coat1("Winter", 100.0);
                Overcoat coat2("Winter", 120.0);
                Overcoat coat3("Spring", 80.0);

                if (coat1 == coat2) {
                    std::cout << "Coat 1 and Coat 2 have the same type." << std::endl;
                }
                else {
                    std::cout << "Coat 1 and Coat 2 have different types." << std::endl;
                }

                coat1 = coat3;
                std::cout << "Coat 1 now has type: " << coat1.getType() << " and price: " << coat1.getPrice() << std::endl;

                if (coat1 > coat3) {
                    std::cout << "Coat 1 has a higher price than Coat 3 of the same type." << std::endl;
                }
                else {
                    std::cout << "Coat 1 does not have a higher price than Coat 3 of the same type." << std::endl;
                }

                open = true;
            }
            else if (usernum == 4) {
                Flat flat1("123 Main St", 100.0, 100000.0);
                Flat flat2("456 Elm St", 120.0, 120000.0);
                Flat flat3("789 Oak St", 100.0, 110000.0);

                if (flat1 == flat3) {
                    std::cout << "Flat 1 and Flat 3 have the same area." << std::endl;
                }
                else {
                    std::cout << "Flat 1 and Flat 3 have different areas." << std::endl;
                }

                flat1 = flat2;
                std::cout << "Flat 1 now has address: " << flat1.getAddress() << " and price: " << flat1.getPrice() << std::endl;

                if (flat2 > flat3) {
                    std::cout << "Flat 2 has a higher price than Flat 3." << std::endl;
                }
                else {
                    std::cout << "Flat 2 does not have a higher price than Flat 3." << std::endl;
                }

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
        return 0;

    }
}