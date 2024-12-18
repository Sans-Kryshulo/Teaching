#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int usernum;
    bool ExitBool = false;
    while (ExitBool == false)
    {
        bool open = false;
        bool exit = false;
        std::cout << "Введите целое число от 1 до 4: ";
        while (open == false)
        {
            while (!(std::cin >> usernum) || std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введено некоректное значения. Спробуйте ёще раз: ";
            }
            if (usernum == 1) {
                ///////////////////////////////
                bool bob = false;
                int number;
                ///////////////////////////////
                std::cout << "Введите целое шестизначное число: ";
                std::cin >> number;
                ///////////////////////////////
                while (bob == false){
                    if (number < 100000 || number > 999999) {
                    std::cout << "Ошибка: Введенное число не является шестизначным. Попробуйте еще раз: ";
                    std::cin >> number;
                    bob = false;
                    }
                    else {
                    bob = true;
                    }
                }
                ///////////////////////////////
                int digit6 = number % 10;
                int digit5 = (number / 10) % 10;
                int digit4 = (number / 100) % 10;
                int digit3 = (number / 1000) % 10;
                int digit2 = (number / 10000) % 10;
                int digit1 = number / 100000;
                ///////////////////////////////
                if (digit1 + digit2 + digit3 == digit4 + digit5 + digit6) {
                    std::cout << "Число " << number << " - счастливое!" << std::endl;
                }
                else {
                    std::cout << "Число " << number << " не является счастливым." << std::endl;
                }
                ///////////////////////////////
                open = true;
            }
            else if (usernum == 2) {
                ///////////////////////////////
                bool bob = false;
                int number;
                ///////////////////////////////
                std::cout << "Введите целое четырехзначное число: ";
                std::cin >> number;
                ///////////////////////////////
                while (bob == false) {
                    if (number < 1000 || number > 9999) {
                        std::cout << "Ошибка: Введенное число не является четырехзначным. Попробуйте еще раз: ";
                        std::cin >> number;
                        bob = false;
                    }
                    else {
                        bob = true;
                    }
                }
                ///////////////////////////////
                int digit1 = (number / 1000) % 10;
                int digit2 = (number / 100) % 10;
                int digit3 = (number / 10) % 10;
                int digit4 = number % 10;
                int newNumber = digit2 * 1000 + digit1 * 100 + digit4 * 10 + digit3;
                ///////////////////////////////
                std::cout << "Исходное число: " << number << std::endl;
                std::cout << "Число после замены: " << newNumber << std::endl;
                ///////////////////////////////
                open = true;
            }
            else if (usernum == 3) {
                ///////////////////////////////
                int numbers[7];
                int maxNumber = numbers[0];
                ///////////////////////////////
                std::cout << "Введите 7 целых чисел:" << std::endl;
                for (int i = 0; i < 7; ++i) {
                    std::cout << "Число " << i + 1 << ": ";
                    std::cin >> numbers[i];
                }          
                ///////////////////////////////
                for (int i = 1; i < 7; ++i) {
                    if (numbers[i] > maxNumber) {
                        maxNumber = numbers[i];
                    }
                }
                std::cout << "Максимальное число: " << maxNumber << std::endl;
                ///////////////////////////////
                open = true;
            }
            else if (usernum == 4) {
                ///////////////////////////////
                const int maxFuelCapacity = 300;
                double distanceAB;
                double distanceBC;
                double cargoWeight;
                double fuelConsumption;
                bool carryingCapacity;
                bool flightDistance;
                ///////////////////////////////
                std::cout << "Введите расстояние между пунктами А и В (в км): ";
                std::cin >> distanceAB;
                std::cout << "Введите расстояние между пунктами В и С (в км): ";
                std::cin >> distanceBC;
                std::cout << "Введите вес груза (в кг): ";
                std::cin >> cargoWeight;
                ///////////////////////////////
                if (cargoWeight <= 500) {
                    fuelConsumption = 1;
                    carryingCapacity = true;
                }
                else if (cargoWeight <= 1000) {
                    fuelConsumption = 4;
                    carryingCapacity = true;
                }
                else if (cargoWeight <= 1500) {
                    fuelConsumption = 7;
                    carryingCapacity = true;
                }
                else if (cargoWeight <= 2000) {
                    fuelConsumption = 9;
                    carryingCapacity = true;
                }
                else {
                    std::cerr << "Ошибка: Самолет не может поднять груз более 2000 кг." << std::endl;
                    carryingCapacity = false;
                }
                ///////////////////////////////
                
                if (carryingCapacity == true) {
                    ///////////////////////////////
                    double requiredFuelAB = distanceAB * fuelConsumption;
                    double requiredFuelBC = distanceBC * fuelConsumption;
                    ///////////////////////////////
                    if (requiredFuelAB > maxFuelCapacity || requiredFuelBC > maxFuelCapacity) {
                        std::cerr << "Ошибка: Невозможно пролететь по введенному маршруту." << std::endl;
                        flightDistance = false;
                    }
                    else {
                        flightDistance = true;
                    }
                    ///////////////////////////////
                    if (flightDistance == true) {
                        if (requiredFuelAB + requiredFuelBC <= maxFuelCapacity)
                        {
                            std::cout << "Дозаправка в пункте B не требуеться." << std::endl;
                        }
                        else {
                            double refuelFuel = abs((maxFuelCapacity - requiredFuelAB) - requiredFuelBC);
                            std::cout << "Минимальное количество топлива для дозаправки в пункте В: " << refuelFuel << " литров." << std::endl;
                        }
                    }
                    else {}
                    ///////////////////////////////
                }
                else {}
                ///////////////////////////////
                open = true;
            }
            else {
                std::cout << "Введено некоректное значения. Спробуйте ёще раз: ";
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
    return 0;
}
