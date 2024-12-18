#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>   
#include <iomanip>
#include <unordered_set>
#include <algorithm>

using namespace std;

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
//Случайное заполнение 2Х2 матрицы
void fillMatrixRandom(int** matrix, int rows, int cols, int a, int b) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = std::rand() % (b - a + 1) + a;
        }
    }
}
//Ручное заполнение 2Х2 матрицы
void fillMatrixManually(int** matrix, int rows, int cols) {
    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Элемент [" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}
//Отображение 2Х2 матрицы
void displayMatrix(const int** matrix, int rows, int cols) {
    int fieldWidth = 4;
    std::cout << std::setw(fieldWidth) << " ";
    for (int j = 0; j < cols; ++j) {
        std::cout << std::setw(fieldWidth) << j + 1;
    }
    std::cout << "\n";
    std::cout << std::setw(fieldWidth) << " ";
    for (int j = 0; j < cols; ++j) {
        std::cout << std::setw(fieldWidth) << "----";
    }
    std::cout << "\n";
    for (int i = 0; i < rows; ++i) {
        std::cout << std::setw(fieldWidth) << i + 1 << "|";
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(fieldWidth) << matrix[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
//Проверка по возрастанию
bool isColumnOrderedAscending(int** matrix, int rows, int col) {
    for (int i = 1; i < rows; ++i) {
        if (matrix[i][col] < matrix[i - 1][col]) {
            return false;
        }
    }
    return true;
}
//Проверка по убыванию
bool isColumnOrderedDescending(int** matrix, int rows, int col) {
    for (int i = 1; i < rows; ++i) {
        if (matrix[i][col] > matrix[i - 1][col]) {
            return false;
        }
    }
    return true;
}
//Случайное заполнение 1Х1 матрицы
void generateRandomArray(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % 20;
    }
}
//Отображение 1Х1 матрицы
void displayArray(const int arr[], int length, const std::string& name) {
    std::cout << name << ": ";
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
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
        std::cout << "Введите целое число от 1 до 4: ";
        while (open == false)
        {
            usernum = getUserInput();
            if (usernum == 1) {
                ////////////////////////////////////////////////////
                int rows;
                int cols;
                int a;
                int b;
                ////////////////////////////////////////////////////
                std::cout << "Введите количество строк: ";
                rows = getUserInput();
                std::cout << "Введите количество столбцов: ";
                cols = getUserInput();
                ///////////////////////////////////////////////////
                int** matrix = new int* [rows];
                for (int i = 0; i < rows; ++i) {
                    matrix[i] = new int[cols];
                }
                ////////////////////////////////////////////////////
                ExitBool = false;
                exit = false;
                std::cout << "Ручное (R) или авто-(А) заполнение матрицы? (R/A)\n";
                while (exit == false)
                {
                    std::string userexit;
                    std::cin >> userexit;
                    if (userexit == "r" || userexit == "R") {
                        ExitBool = true;
                        exit = true;
                        fillMatrixManually(matrix, rows, cols);
                    }
                    else if (userexit == "a" || userexit == "A") {
                        ExitBool = false;
                        exit = true;
                        std::cout << "Введите нижнюю границу случайных чисел: ";
                        a = getUserInput();
                        std::cout << "Введите верхнюю границу случайных чисел: ";
                        b = getUserInput();
                        fillMatrixRandom(matrix, rows, cols, a, b);
                    }
                    else {
                        ExitBool = false;
                        exit = false;
                        std::cout << "Введено некоректное значения. Спробуйте ёще раз. \n";
                    }
                }
                std::cout << "Случайно заполненная матрица:\n";
                displayMatrix(const_cast<const int**>(matrix), rows, cols);
                ///////////////////////////////////////////////////
                for (int j = 0; j < cols; ++j) {
                    bool containsPositive = false;
                    for (int i = 0; i < rows; ++i) {
                        if (matrix[i][j] > 0) {
                            containsPositive = true;
                            break;
                        }
                    }
                    if (containsPositive) {
                        for (int i = 0; i < rows; ++i) {
                            for (int k = j; k < cols - 1; ++k) {
                                matrix[i][k] = matrix[i][k + 1];
                            }
                        }
                        --cols;
                        --j;
                    }
                }
                std::cout << "Матрица после удаления столбцов с положительными элементами:\n";
                displayMatrix(const_cast<const int**>(matrix), rows, cols);
                ///////////////////////////////////////////////////
                for (int i = 0; i < rows; ++i) {
                    delete[] matrix[i];
                }
                delete[] matrix;
                ///////////////////////////////////////////////////
                open = true;
            }
            else if (usernum == 2) {
                ////////////////////////////////////////////////////
                int rows;
                int cols;
                int a;
                int b;
                ////////////////////////////////////////////////////
                std::cout << "Введите количество строк: ";
                rows = getUserInput();
                std::cout << "Введите количество столбцов: ";
                cols = getUserInput();
                ///////////////////////////////////////////////////
                int** matrix = new int* [rows];
                for (int i = 0; i < rows; ++i) {
                    matrix[i] = new int[cols];
                }
                ////////////////////////////////////////////////////
                ExitBool = false;
                exit = false;
                std::cout << "Ручное (R) или авто-(А) заполнение матрицы? (R/A)\n";
                while (exit == false)
                {
                    std::string userexit;
                    std::cin >> userexit;
                    if (userexit == "r" || userexit == "R") {
                        ExitBool = true;
                        exit = true;
                        fillMatrixManually(matrix, rows, cols);
                    }
                    else if (userexit == "a" || userexit == "A") {
                        ExitBool = false;
                        exit = true;
                        std::cout << "Введите нижнюю границу случайных чисел: ";
                        a = getUserInput();
                        std::cout << "Введите верхнюю границу случайных чисел: ";
                        b = getUserInput();
                        fillMatrixRandom(matrix, rows, cols, a, b);
                    }
                    else {
                        ExitBool = false;
                        exit = false;
                        std::cout << "Введено некоректное значения. Спробуйте ёще раз. \n";
                    }
                }
                std::cout << "Случайно заполненная матрица:\n";
                displayMatrix(const_cast<const int**>(matrix), rows, cols);
                ///////////////////////////////////////////////////
                for (int i = 0; i < rows; ++i) {
                    std::unordered_set<int> uniqueElements(matrix[i], matrix[i] + cols);
                    if (uniqueElements.size() == static_cast<size_t>(cols)) {
                        delete[] matrix[i];
                        std::copy(matrix + i + 1, matrix + rows, matrix + i);
                        --rows;
                        --i;
                    }
                }
                std::cout << "Матрица после удаления строк без повторяющихся элементов:\n";
                displayMatrix(const_cast<const int**>(matrix), rows, cols);
                ///////////////////////////////////////////////////
                for (int i = 0; i < rows; ++i) {
                    delete[] matrix[i];
                }
                delete[] matrix;
                ///////////////////////////////////////////////////
                open = true;
            }
            else if (usernum == 3) {
                ////////////////////////////////////////////////////
                int rows;
                int cols;
                int a;
                int b;
                ////////////////////////////////////////////////////
                std::cout << "Введите количество строк: ";
                rows = getUserInput();
                std::cout << "Введите количество столбцов: ";
                cols = getUserInput();
                ///////////////////////////////////////////////////
                int** matrix = new int* [rows];
                for (int i = 0; i < rows; ++i) {
                    matrix[i] = new int[cols];
                }
                ////////////////////////////////////////////////////
                ExitBool = false;
                exit = false;
                std::cout << "Ручное (R) или авто-(А) заполнение матрицы? (R/A)\n";
                while (exit == false)
                {
                    std::string userexit;
                    std::cin >> userexit;
                    if (userexit == "r" || userexit == "R") {
                        ExitBool = true;
                        exit = true;
                        fillMatrixManually(matrix, rows, cols);
                    }
                    else if (userexit == "a" || userexit == "A") {
                        ExitBool = false;
                        exit = true;
                        std::cout << "Введите нижнюю границу случайных чисел: ";
                        a = getUserInput();
                        std::cout << "Введите верхнюю границу случайных чисел: ";
                        b = getUserInput();
                        fillMatrixRandom(matrix, rows, cols, a, b);
                    }
                    else {
                        ExitBool = false;
                        exit = false;
                        std::cout << "Введено некоректное значения. Спробуйте ёще раз. \n";
                    }
                }
                std::cout << "Случайно заполненная матрица:\n";
                displayMatrix(const_cast<const int**>(matrix), rows, cols);
                ///////////////////////////////////////////////////
                int maxElement = 0; // Инициализация максимального элемента

                for (int j = 0; j < cols; ++j) {
                    if (isColumnOrderedAscending(matrix, rows, j) || isColumnOrderedDescending(matrix, rows, j)) {
                        // Столбец упорядочен (по возрастанию или убыванию)
                        // Найдем максимальный элемент в этом столбце
                        for (int i = 0; i < rows; ++i) {
                            maxElement = std::max(maxElement, matrix[i][j]);
                        }
                    }
                }

                if (maxElement != 0) {
                    std::cout << "Максимальный элемент среди упорядоченных столбцов: " << maxElement << std::endl;
                }
                else {
                    std::cout << "Упорядоченные столбцы отсутствуют. Максимальный элемент: 0" << std::endl;
                }

                ///////////////////////////////////////////////////
                for (int i = 0; i < rows; ++i) {
                    delete[] matrix[i];
                }
                delete[] matrix;
                ///////////////////////////////////////////////////
                open = true;
            }
            else if (usernum == 4) {
                ///////////////////////////////////////////////////
                int length1;
                int length2;
                std::cout << "Введите длину первого массива: ";
                length1 = getUserInput();
                std::cout << "Введите длину второго массива: ";
                length2 = getUserInput();
                ///////////////////////////////////////////////////
                int* array1 = new int[length1];
                int* array2 = new int[length2];
                ///////////////////////////////////////////////////
                generateRandomArray(array1, length1);
                generateRandomArray(array2, length2);
                displayArray(array1, length1, "Первый массив");
                displayArray(array2, length2, "Второй массив");
                ///////////////////////////////////////////////////
                std::sort(array1, array1 + length1);
                std::sort(array2, array2 + length2);
                int* intersectionArray = new int[std::min(length1, length2)];
                int* intersectionEnd = std::set_intersection(array1, array1 + length1, array2, array2 + length2, intersectionArray);
                displayArray(intersectionArray, intersectionEnd - intersectionArray, "Массив из общих элементов");
                int* symmetricDifferenceArray = new int[length1 + length2];
                int* symmetricDifferenceEnd = std::set_symmetric_difference(array1, array1 + length1, array2, array2 + length2, symmetricDifferenceArray);
                displayArray(symmetricDifferenceArray, symmetricDifferenceEnd - symmetricDifferenceArray, "Массив из элементов, присутствующих только в одном из массивов");
                ///////////////////////////////////////////////////
                delete[] array1;
                delete[] array2;
                delete[] intersectionArray;
                delete[] symmetricDifferenceArray;
                ///////////////////////////////////////////////////
                open = true;
            }
            else {
                std::cout << "Введенное значение не в диапазоне. Спробуйте ёще раз: ";
                open = false;
            }
        }
        ExitBool = false;
        exit = false;
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