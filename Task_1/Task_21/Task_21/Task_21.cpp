#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include "CarShowroom.h"
#include "Functors.h"
#include "FunctorsBetter.h"

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
        std::cout << "Введите целое число от 1 до 3: ";
        while (open == false)
        {
            usernum = getUserInput();
            if (usernum == 1) {
                CarShowroom showroom;

                showroom.AddCar(Car("Toyota Camry", 2020, 2.5, 24000));
                showroom.AddCar(Car("Honda Accord", 2019, 2.0, 22000));
                showroom.AddCar(Car("BMW 320i", 2021, 2.0, 35000));

                std::cout << "All cars:" << std::endl;
                showroom.DisplayCars();

                std::cout << "\nSorted by name:" << std::endl;
                showroom.SortCars([](const Car& a, const Car& b) { return a.GetName() < b.GetName(); });
                showroom.DisplayCars();

                std::cout << "\nSorted by price:" << std::endl;
                showroom.SortCars([](const Car& a, const Car& b) { return a.GetPrice() < b.GetPrice(); });
                showroom.DisplayCars();

                std::cout << "\nFind by name \"Honda Accord\":" << std::endl;
                showroom.FindCarByName("Honda Accord");

                std::cout << "\nFind by year 2020:" << std::endl;
                showroom.FindCarByYear(2020);

                std::cout << "\nRemoving car \"BMW 320i\"" << std::endl;
                showroom.RemoveCar("BMW 320i");

                std::cout << "\nAll cars after removal:" << std::endl;
                showroom.DisplayCars();

                open = true;
            }
            else if (usernum == 2) {
                std::vector<int> data = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

                std::cout << "Original data: ";
                for (const auto& val : data) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                MinValue minValue;
                std::cout << "Minimum value: " << minValue(data) << std::endl;

                MaxValue maxValue;
                std::cout << "Maximum value: " << maxValue(data) << std::endl;

                SortDescending sortDescending;
                sortDescending(data);
                std::cout << "Sorted descending: ";
                for (const auto& val : data) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                SortAscending sortAscending;
                sortAscending(data);
                std::cout << "Sorted ascending: ";
                for (const auto& val : data) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                IncreaseBy<int> increaseBy(5);
                increaseBy(data);
                std::cout << "Increased by 5: ";
                for (const auto& val : data) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                DecreaseBy<int> decreaseBy(3);
                decreaseBy(data);
                std::cout << "Decreased by 3: ";
                for (const auto& val : data) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                RemoveValue removeValue(62);
                removeValue(data);
                std::cout << "Removed value 62: ";
                for (const auto& val : data) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                open = true;
            }
            else if (usernum == 3) {
                // Тестирование на std::vector<int>
                std::vector<int> vecData = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

                std::cout << "Testing on std::vector<int>" << std::endl;
                MinValueBetter<std::vector<int>> minValueBetter;
                std::cout << "Minimum value: " << minValueBetter(vecData) << std::endl;

                MaxValueBetter<std::vector<int>> maxValueBetter;
                std::cout << "Maximum value: " << maxValueBetter(vecData) << std::endl;

                SortDescendingBetter<std::vector<int>> sortDescendingBetter;
                sortDescendingBetter(vecData);
                std::cout << "Sorted descending: ";
                for (const auto& val : vecData) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                SortAscendingBetter<std::vector<int>> sortAscendingBetter;
                sortAscendingBetter(vecData);
                std::cout << "Sorted ascending: ";
                for (const auto& val : vecData) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                IncreaseByBetter<std::vector<int>, int> increaseByBetter(5);
                increaseByBetter(vecData);
                std::cout << "Increased by 5: ";
                for (const auto& val : vecData) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                DecreaseByBetter<std::vector<int>, int> decreaseByBetter(3);
                decreaseByBetter(vecData);
                std::cout << "Decreased by 3: ";
                for (const auto& val : vecData) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                RemoveValueBetter<std::vector<int>> removeValueBetter(67);
                removeValueBetter(vecData);
                std::cout << "Removed value 67: ";
                for (const auto& val : vecData) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                // Тестирование на std::list<int>
                std::list<int> listData = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

                std::cout << "\nTesting on std::list<int>" << std::endl;
                MinValueBetter<std::list<int>> minValueBetterList;
                std::cout << "Minimum value: " << minValueBetterList(listData) << std::endl;

                MaxValueBetter<std::list<int>> maxValueBetterList;
                std::cout << "Maximum value: " << maxValueBetterList(listData) << std::endl;

                SortDescendingBetter<std::list<int>> sortDescendingBetterList;
                sortDescendingBetterList(listData);
                std::cout << "Sorted descending: ";
                for (const auto& val : listData) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                SortAscendingBetter<std::list<int>> sortAscendingBetterList;
                sortAscendingBetterList(listData);
                std::cout << "Sorted ascending: ";
                for (const auto& val : listData) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                IncreaseByBetter<std::list<int>, int> increaseByBetterList(5);
                increaseByBetterList(listData);
                std::cout << "Increased by 5: ";
                for (const auto& val : listData) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                DecreaseByBetter<std::list<int>, int> decreaseByBetterList(3);
                decreaseByBetterList(listData);
                std::cout << "Decreased by 3: ";
                for (const auto& val : listData) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                RemoveValueBetter<std::list<int>> removeValueBetterList(67);
                removeValueBetterList(listData);
                std::cout << "Removed value 67: ";
                for (const auto& val : listData) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;


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