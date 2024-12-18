#include <iostream>
#include <string>
#include <sstream>

int getUserInput() {
    while (true) {
        std::string input;
        std::cin >> input;
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

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysDifference(int day1, int month1, int year1, int day2, int month2, int year2) {
    const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days1 = day1;
    for (int i = 1; i < month1; ++i) {
        days1 += daysInMonth[i];
    }
    if (month1 > 2 && isLeapYear(year1)) {
        days1 += 1;
    }
    for (int i = 1; i < year1; ++i) {
        days1 += isLeapYear(i) ? 366 : 365;
    }
    int days2 = day2;
    for (int i = 1; i < month2; ++i) {
        days2 += daysInMonth[i];
    }
    if (month2 > 2 && isLeapYear(year2)) {
        days2 += 1;
    }
    for (int i = 1; i < year2; ++i) {
        days2 += isLeapYear(i) ? 366 : 365;
    }
    return days2 - days1;
}

void displayArray(const int* array, int size) {
    std::cout << "Масив:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void fillArrayWithRandomNumbers(int* array, int size) {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < size; ++i) {
        array[i] = std::rand() % 101 - 50;
    }
}

double calculateAverage(const int array[], int size) {
    if (size == 0) {
        std::cerr << "Ошибка: Нельзя вычислить среднее арифметическое для пустого массива." << std::endl;
        return 0.0;
    }

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    return static_cast<double>(sum) / size;
}

void countPositiveNegativeZero(const int array[], int size, int& positiveCount, int& negativeCount, int& zeroCount) {
    positiveCount = 0;
    negativeCount = 0;
    zeroCount = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i] > 0) {
            positiveCount++;
        }
        else if (array[i] < 0) {
            negativeCount++;
        }
        else {
            zeroCount++;
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
                ////////////////////////////////
                int day1;
                int month1;
                int year1;
                int day2;
                int month2;
                int year2;
                ////////////////////////////////
                std::cout << "Введите первую дату (день месяц год): ";
                day1 = getUserInput();
                month1 = getUserInput();
                year1 = getUserInput();
                ////////////////////////////////
                std::cout << "Введите вторую дату (день месяц год): ";
                day2 = getUserInput();
                month2 = getUserInput();
                year2 = getUserInput();
                ////////////////////////////////
                int difference = abs(daysDifference(day1, month1, year1, day2, month2, year2));
                std::cout << "Разность в днях между двумя датами: " << difference << " дней" << std::endl;
                open = true;
            }
            else if (usernum == 2) {
                ///////////////////////////////
                const int size = 20;
                int myArray[size];
                ///////////////////////////////
                fillArrayWithRandomNumbers(myArray, size);
                displayArray(myArray, size);
                ///////////////////////////////
                double average = calculateAverage(myArray, size);
                std::cout << "Среднее арифметическое элементов массива: " << average << std::endl;
                open = true;
            }
            else if (usernum == 3) {
                ///////////////////////////////
                const int size = 20;
                int myArray[size];
                int positiveCount;
                int negativeCount;
                int zeroCount;
                ///////////////////////////////
                fillArrayWithRandomNumbers(myArray, size);
                displayArray(myArray, size);
                ///////////////////////////////
                countPositiveNegativeZero(myArray, size, positiveCount, negativeCount, zeroCount);
                std::cout << "Количество положительных элементов: " << positiveCount << std::endl;
                std::cout << "Количество отрицательных элементов: " << negativeCount << std::endl;
                std::cout << "Количество нулевых элементов: " << zeroCount << std::endl;
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
    return 0;
}