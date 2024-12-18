#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>

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
/////////Для 1 задания/////////
// Инициализация квадратной матрицы (int)
void initializeMatrix(std::vector<std::vector<int>>& matrix, int size) {
    matrix.resize(size, std::vector<int>(size, 0));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Здесь можно использовать любую логику для инициализации элементов
            matrix[i][j] = i * size + j + 1;
        }
    }
}
// Инициализация квадратной матрицы (double)
void initializeMatrix(std::vector<std::vector<double>>& matrix, int size) {
    matrix.resize(size, std::vector<double>(size, 0.0));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Здесь можно использовать любую логику для инициализации элементов
            matrix[i][j] = (i * size + j + 1) * 0.5;
        }
    }
}
// Инициализация квадратной матрицы (char)
void initializeMatrix(std::vector<std::vector<char>>& matrix, int size) {
    matrix.resize(size, std::vector<char>(size, 'A'));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Здесь можно использовать любую логику для инициализации элементов
            matrix[i][j] = static_cast<char>('A' + i * size + j);
        }
    }
}
// Вывод матрицы на экран (int)
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            std::cout << std::setw(4) << elem << " ";
        }
        std::cout << '\n';
    }
}
// Вывод матрицы на экран (double)
void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double elem : row) {
            std::cout << std::setw(8) << std::fixed << std::setprecision(2) << elem << " ";
        }
        std::cout << '\n';
    }
}
// Вывод матрицы на экран (char)
void printMatrix(const std::vector<std::vector<char>>& matrix) {
    for (const auto& row : matrix) {
        for (char elem : row) {
            std::cout << std::setw(4) << elem << " ";
        }
        std::cout << '\n';
    }
}
// Определение максимального и минимального элемента на главной диагонали матрицы (int)
void findMinMaxDiagonal(const std::vector<std::vector<int>>& matrix, int& maxDiagonal, int& minDiagonal) {
    int size = matrix.size();
    if (size > 0) {
        maxDiagonal = matrix[0][0];
        minDiagonal = matrix[0][0];

        for (int i = 1; i < size; ++i) {
            maxDiagonal = std::max(maxDiagonal, matrix[i][i]);
            minDiagonal = std::min(minDiagonal, matrix[i][i]);
        }
    }
}
// Определение максимального и минимального элемента на главной диагонали матрицы (double)
void findMinMaxDiagonal(const std::vector<std::vector<double>>& matrix, double& maxDiagonal, double& minDiagonal) {
    int size = matrix.size();
    if (size > 0) {
        maxDiagonal = matrix[0][0];
        minDiagonal = matrix[0][0];

        for (int i = 1; i < size; ++i) {
            maxDiagonal = std::max(maxDiagonal, matrix[i][i]);
            minDiagonal = std::min(minDiagonal, matrix[i][i]);
        }
    }
}
// Определение максимального и минимального элемента на главной диагонали матрицы (char)
void findMinMaxDiagonal(const std::vector<std::vector<char>>& matrix, char& maxDiagonal, char& minDiagonal) {
    int size = matrix.size();
    if (size > 0) {
        maxDiagonal = matrix[0][0];
        minDiagonal = matrix[0][0];

        for (int i = 1; i < size; ++i) {
            maxDiagonal = std::max(maxDiagonal, matrix[i][i]);
            minDiagonal = std::min(minDiagonal, matrix[i][i]);
        }
    }
}
// Сортировка элементов по возрастанию отдельно для каждой строки матрицы (int)
void sortRowsAscending(std::vector<std::vector<int>>& matrix) {
    for (auto& row : matrix) {
        std::sort(row.begin(), row.end());
    }
}
// Сортировка элементов по возрастанию отдельно для каждой строки матрицы (double)
void sortRowsAscending(std::vector<std::vector<double>>& matrix) {
    for (auto& row : matrix) {
        std::sort(row.begin(), row.end());
    }
}
// Сортировка элементов по возрастанию отдельно для каждой строки матрицы (char)
void sortRowsAscending(std::vector<std::vector<char>>& matrix) {
    for (auto& row : matrix) {
        std::sort(row.begin(), row.end());
    }
}
/////////Для 2 задания/////////
int findGCD(int a, int b) {
    // Базовый случай
    if (b == 0) {
        return a;
    }
    else {
        // Рекурсивный случай
        return findGCD(b, a % b);
    }
}
/////////Для 3 задания/////////
// Генерация четырехзначного числа
int generateSecretNumber() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    return 1000 + std::rand() % 9000;
}
// Проверка наличия цифры в числе
bool containsDigit(int number, int digit) {
    while (number > 0) {
        if (number % 10 == digit) {
            return true;
        }
        number /= 10;
    }
    return false;
}
// Подсчет быков
int countBulls(int secret, int guess) {
    int bulls = 0;
    for (int i = 0; i < 4; ++i) {
        if ((secret % 10) == (guess % 10)) {
            bulls++;
        }
        secret /= 10;
        guess /= 10;
    }
    return bulls;
}
// Подсчет коров
int countCows(int secret, int guess) {
    int cows = 0;
    for (int i = 0; i < 4; ++i) {
        if (containsDigit(secret, guess % 10)) {
            cows++;
        }
        guess /= 10;
    }
    return cows;
}
// Проверка на правильность введенного числа
bool isValidInput(int number) {
    if (number >= 1000 && number <= 9999) {
        std::vector<int> digits(10, 0);
        while (number > 0) {
            int digit = number % 10;
            if (digits[digit] == 1) {
                return false;
            }
            digits[digit] = 1;
            number /= 10;
        }
        return true;
    }
    return false;
}
// Основная функция игры
void playGame(int secret, int attempts) {
    ////////////////////////////////
    int guess;
    std::cout << "Введите ваше предположение (четырехзначное число): ";
    std::cin >> guess;
    if (!isValidInput(guess)) {
        std::cout << "Неправильный ввод. Попробуйте еще раз.\n";
        playGame(secret, attempts);
        return;
    }
    ////////////////////////////////
    int bulls = countBulls(secret, guess);
    int cows = countCows(secret, guess);
    std::cout << "Быки: " << bulls << ", Коровы: " << cows << std::endl;
    if (bulls == 4) {
        std::cout << "Поздравляю, вы угадали число! Количество попыток: " << attempts << std::endl;
    }
    else {
        playGame(secret, attempts + 1);
    }
    ////////////////////////////////
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
                const int size = 3;
                int maxDiagonalInt;
                int minDiagonalInt;
                double maxDiagonalDouble;
                double minDiagonalDouble;
                char maxDiagonalChar;
                char minDiagonalChar;
                ////////////////////////////////
                // Инициализация и вывод матрицы с целыми числами
                std::vector<std::vector<int>> matrixInt;
                initializeMatrix(matrixInt, size);
                std::cout << "Матрица с целыми числами:\n";
                printMatrix(matrixInt);
                // Определение максимального и минимального элемента на главной диагонали
                findMinMaxDiagonal(matrixInt, maxDiagonalInt, minDiagonalInt);
                std::cout << "Максимальный элемент на главной диагонали: " << maxDiagonalInt << '\n';
                std::cout << "Минимальный элемент на главной диагонали: " << minDiagonalInt << '\n';
                // Сортировка элементов по возрастанию отдельно для каждой строки
                sortRowsAscending(matrixInt);
                std::cout << "Матрица после сортировки элементов по возрастанию в каждой строке:\n";
                printMatrix(matrixInt);
                // Инициализация и вывод матрицы с числами с плавающей запятой
                std::vector<std::vector<double>> matrixDouble;
                initializeMatrix(matrixDouble, size);
                std::cout << "\nМатрица с числами с плавающей запятой:\n";
                printMatrix(matrixDouble);
                // Определение максимального и минимального элемента на главной диагонали
                findMinMaxDiagonal(matrixDouble, maxDiagonalDouble, minDiagonalDouble);
                std::cout << "Максимальный элемент на главной диагонали: " << maxDiagonalDouble << '\n';
                std::cout << "Минимальный элемент на главной диагонали: " << minDiagonalDouble << '\n';
                // Сортировка элементов по возрастанию отдельно для каждой строки
                sortRowsAscending(matrixDouble);
                std::cout << "Матрица после сортировки элементов по возрастанию в каждой строке:\n";
                printMatrix(matrixDouble);
                // Инициализация и вывод матрицы с символами
                std::vector<std::vector<char>> matrixChar;
                initializeMatrix(matrixChar, size);
                std::cout << "\nМатрица с символами:\n";
                printMatrix(matrixChar);
                // Определение максимального и минимального элемента на главной диагонали
                findMinMaxDiagonal(matrixChar, maxDiagonalChar, minDiagonalChar);
                std::cout << "Максимальный элемент на главной диагонали: " << maxDiagonalChar << '\n';
                std::cout << "Минимальный элемент на главной диагонали: " << minDiagonalChar << '\n';
                // Сортировка элементов по возрастанию отдельно для каждой строки
                sortRowsAscending(matrixChar);
                std::cout << "Матрица после сортировки элементов по возрастанию в каждой строке:\n";
                printMatrix(matrixChar);
                ////////////////////////////////
                open = true;
            }
            else if (usernum == 2) {
                ///////////////////////////////
                int num1;
                int num2;
                int gcd;
                std::cout << "Введите первое целое число: ";
                num1 = getUserInput();
                std::cout << "Введите второе целое число: ";
                num2 = getUserInput();
                ///////////////////////////////
                gcd = findGCD(num1, num2);
                std::cout << "Наибольший общий делитель чисел " << num1 << " и " << num2 << " равен: " << gcd << std::endl;
                ///////////////////////////////
                open = true;
            }
            else if (usernum == 3) {
                ///////////////////////////////
                int secretNumber = generateSecretNumber();
                std::cout << "Добро пожаловать в игру 'Быки и коровы'!\n";
                std::cout << "Попробуйте угадать четырехзначное число, загаданное программой.\n";
                playGame(secretNumber, 1);
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