#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <vector>
//#include <string>

int getUserInput() {
    while (true) {
        std::string input;
        std::cin >> input;
        //std::getline(std::cin, input);
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

int findSumOfDigits(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

double findAverageOfPositiveElements(const int* array, int size) {
    int positiveCount = 0;
    int sumOfPositive = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] > 0) {
            positiveCount++;
            sumOfPositive += array[i];
        }
    }
    if (positiveCount == 0) {
        std::cerr << "В массиве нет положительных элементов." << std::endl;
        return 0.0;
    }
    return static_cast<double>(sumOfPositive) / positiveCount;
}

void findMaxNegativeElement(const int* array, int size) {
    int maxNegative = INT_MIN;
    int position = -1;

    for (int i = 0; i < size; ++i) {
        if (array[i] < 0 && array[i] > maxNegative) {
            maxNegative = array[i];
            position = i+1;
        }
    }

    if (position != -1) {
        std::cout << "Максимальный отрицательный элемент: " << maxNegative << std::endl;
        std::cout << "Позиция в массиве: " << position << std::endl;
    }
    else {
        std::cout << "В массиве нет отрицательных частей." << std::endl;
    }
}

int findMostFrequentNumber(const int* array, int size) {
    std::unordered_map<int, int> frequencyMap;
    for (int i = 0; i < size; ++i) {
        frequencyMap[array[i]]++;
    }
    int mostFrequentNumber = array[0];
    int maxFrequency = 1;
    for (const auto& entry : frequencyMap) {
        if (entry.second > maxFrequency) {
            mostFrequentNumber = entry.first;
            maxFrequency = entry.second;
        }
    }
    return mostFrequentNumber;
}

int findMaxElementDivisibleBy3(const int* array, int size) {
    int maxElement = INT_MIN;
    for (int i = 1; i < size; i += 2) {
        if (array[i] % 3 == 0 && array[i] > maxElement) {
            maxElement = array[i];
        }
    }
    return maxElement;
}

void swapElements(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void processArray(int* array, int size) {
    int maxEven = INT_MIN;
    int minOdd = INT_MAX;
    int maxEvenIndex = -1;
    int minOddIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (array[i] % 2 == 0 && array[i] > maxEven) {
            maxEven = array[i];
            maxEvenIndex = i;
        }
        else if (array[i] % 2 != 0 && array[i] < minOdd) {
            minOdd = array[i];
            minOddIndex = i;
        }
    }
    if (maxEvenIndex != -1 && minOddIndex != -1) {
        swapElements(array[maxEvenIndex], array[minOddIndex]);
    }
    else {
        for (int i = 0; i < size; ++i) {
            array[i] = 0;
        }
    }
}
/*
void shiftArray(std::vector<std::vector<int>>& array, int shifts, const std::string& direction) {
    int rows = array.size();
    int columns = array[0].size();
    std::vector<std::vector<int>> newArray(rows, std::vector<int>(columns, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (direction == "л" || direction == "Л") {
                newArray[i][j] = array[i][(j + shifts) % columns];
            }
            else if (direction == "п" || direction == "П") {
                newArray[i][j] = array[i][(j - shifts + columns) % columns];
            }
            else if (direction == "в" || direction == "В") {
                newArray[i][j] = array[(i + shifts) % rows][j];
            }
            else if (direction == "н" || direction == "Н") {
                newArray[i][j] = array[(i - shifts + rows) % rows][j];
            }
        }
    }
    array = newArray;
}

void displayArray2(const std::vector<std::vector<int>>& array) {
    for (const auto& row : array) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}
*/
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
        std::cout << "Введите целое число от 1 до 8: ";
        while (open == false)
        {
            usernum = getUserInput();
            if (usernum == 1) {
                ///////////////////////////////
                const int size = 3;
                int totalSum = 0;
                int myArray[size];
                ///////////////////////////////
                fillArrayWithRandomNumbers(myArray, size);
                displayArray(myArray, size);
                ///////////////////////////////
                for (int i = 0; i < size; ++i) {
                    totalSum += findSumOfDigits(myArray[i]);
                }

                std::cout << "Сумма цифр всех чисел массива: " << totalSum << std::endl;
                open = true;
            }
            else if (usernum == 2) {
                ///////////////////////////////
                const int size = 8;
                int myArray[size];
                ///////////////////////////////
                fillArrayWithRandomNumbers(myArray, size);
                displayArray(myArray, size);
                ///////////////////////////////
                double average = findAverageOfPositiveElements(myArray, size);
                if (average != 0.0) {
                    std::cout << "Среднее арифметическое положительных элементов: " << average << std::endl;
                }
                open = true;
            }
            else if (usernum == 3) {
                ///////////////////////////////
                const int size = 8;
                int myArray[size];
                ///////////////////////////////
                fillArrayWithRandomNumbers(myArray, size);
                displayArray(myArray, size);
                findMaxNegativeElement(myArray, size);
                ///////////////////////////////
                open = true;
            }
            else if (usernum == 4) {
                ///////////////////////////////
                const int size = 40;  
                int myArray[size];
                ///////////////////////////////
                fillArrayWithRandomNumbers(myArray, size);
                displayArray(myArray, size);
                ///////////////////////////////
                int mostFrequent = findMostFrequentNumber(myArray, size);
                std::cout << "Чаще встречается число: " << mostFrequent << std::endl;
                ///////////////////////////////
                open = true;
            }
            else if (usernum == 5) {
                ///////////////////////////////
                const int size = 40;
                int myArray[size];
                ///////////////////////////////
                fillArrayWithRandomNumbers(myArray, size);
                displayArray(myArray, size);
                ///////////////////////////////
                int maxElement = findMaxElementDivisibleBy3(myArray, size);
                if (maxElement != INT_MIN) {
                    std::cout << "Наибольший элемент, который нацело делится на 3: " << maxElement << std::endl;
                }
                else {
                    std::cout << "В массиве отсутствуют элементы, которые нацело делятся на 3 среди имеющих нечетные индексы." << std::endl;
                }
                ///////////////////////////////
                open = true;
            }
            else if (usernum == 6) {
                ///////////////////////////////
                const int size = 20;
                int myArray[size];
                ///////////////////////////////
                fillArrayWithRandomNumbers(myArray, size);
                displayArray(myArray, size);
                processArray(myArray, size);
                ///////////////////////////////
                std::cout << "Массив после обробки:" << std::endl;
                displayArray(myArray, size);
                ///////////////////////////////
                open = true;
            }
            else if (usernum == 7) {
                ///////////////////////////////
                int rows;
                int columns;
                int initialValue;
                ///////////////////////////////
                std::cout << "Введите количество строк: ";
                rows = getUserInput();
                std::cout << "Введите количество столбцов: ";
                columns = getUserInput();
                std::cout << "Введите исходное значение: ";
                initialValue = getUserInput();
                ///////////////////////////////
                std::vector<std::vector<int>> array(rows, std::vector<int>(columns, 0));
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < columns; ++j) {
                        if (j == 0) {
                            array[i][j] = initialValue;
                        }
                        else {
                            array[i][j] = array[i][j - 1] * 2;
                        }
                    }
                }
                ///////////////////////////////
                std::cout << "Созданный двухмерный массив:" << std::endl;
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < columns; ++j) {
                        std::cout << array[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                ///////////////////////////////
                open = true;
            }
            else if (usernum == 8) {
                ///////////////////////////////
                const int rows = 2;
                const int columns = 6;
                int myArray[rows][columns];
                ///////////////////////////////
                srand(static_cast<unsigned>(time(0)));
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < columns; ++j) {
                        myArray[i][j] = rand() % 10;
                    }
                }
                ///////////////////////////////
                std::cout << "Исходный массив:" << std::endl;
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < columns; ++j) {
                        std::cout << myArray[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                ///////////////////////////////
                int shifts;
                char direction;
                std::cout << "Введите количество сдвигов: ";
                shifts = getUserInput();
                std::cout << "Введите направление (l - влево, r - вправо, u - вверх, d - вниз): ";
                std::cin >> direction;
                ///////////////////////////////
                if (direction == 'r' || direction == 'R') {
                    for (int i = 0; i < rows; ++i) {
                        for (int shift = 0; shift < shifts; ++shift) {
                            int temp = myArray[i][columns - 1];
                            for (int j = columns - 1; j > 0; --j) {
                                myArray[i][j] = myArray[i][j - 1];
                            }
                            myArray[i][0] = temp;
                        }
                    }
                }
                else if (direction == 'l' || direction == 'L') {
                    for (int i = 0; i < rows; ++i) {
                        for (int shift = 0; shift < shifts; ++shift) {
                            int temp = myArray[i][0];
                            for (int j = 0; j < columns - 1; ++j) {
                                myArray[i][j] = myArray[i][j + 1];
                            }
                            myArray[i][columns - 1] = temp;
                        }
                    }
                }
                else if (direction == 'u' || direction == 'U') {
                    for (int shift = 0; shift < shifts; ++shift) {
                        int temp = myArray[0][0];
                        for (int i = 0; i < rows - 1; ++i) {
                            myArray[i][0] = myArray[i + 1][0];
                        }
                        myArray[rows - 1][0] = temp;
                    }
                }
                else if (direction == 'd' || direction == 'D') {
                    for (int shift = 0; shift < shifts; ++shift) {
                        int temp = myArray[rows - 1][0];
                        for (int i = rows - 1; i > 0; --i) {
                            myArray[i][0] = myArray[i - 1][0];
                        }
                        myArray[0][0] = temp;
                    }
                }
                ///////////////////////////////
                std::cout << "Результат после сдвига:" << std::endl;
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < columns; ++j) {
                        std::cout << myArray[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                ///////////////////////////////
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