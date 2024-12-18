﻿#include <iostream>
#include <sstream>
#include "Stop.h"
#include "Printer.h"

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
                Stop stop1(2.0, 5.0, false);
                Stop stop2(1.5, 4.0, true);

                int maxPassengers = 10;
                int simulationTime = 1;

                std::cout << "Simulating stop 1:" << std::endl;
                stop1.simulate(maxPassengers, simulationTime);

                std::cout << "\nSimulating stop 2:" << std::endl;
                stop2.simulate(maxPassengers, simulationTime);

                open = true;
            }
            else if (usernum == 2) {
                Printer printer;

                printer.addRequest("User1", 1);
                printer.addRequest("User2", 3);
                printer.addRequest("User3", 2);

                printer.processNextRequest();
                printer.processNextRequest();
                printer.processNextRequest();

                printer.printStatistics();

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