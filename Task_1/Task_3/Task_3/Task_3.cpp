#include <iostream>
#include <string>
#include <sstream>

int getUserInput() {
    while (true) {
        std::string input;
        std::cin >> input;
        //std::getline(std::cin, input);
        // Используем stringstream для попытки преобразовать введенную строку в целое число
        std::stringstream stream(input);
        int result;
        if (stream >> result && stream.eof()) {
            // Ввод успешно преобразован в целое число
            return result;
        }
        else {
            std::cout << "Ошибка! Введено некоректное значения. Спробуйте ёще раз: ";
        }
    }
}

int countNumbersWithSameDigits() {
    int count = 0;
    for (int i = 100; i <= 999; ++i) {
        ////////////////////////////////////
        int digit1 = i / 100;       // Сотни
        int digit2 = (i / 10) % 10; // Десятки
        int digit3 = i % 10;        // Единицы
        ////////////////////////////////////
        if (digit1 == digit2 || digit1 == digit3 || digit2 == digit3) {
            // У числа есть две одинаковые цифры
            count++;
        }
    }
    return count;
}

int countNumbersWithAllDifferentDigits() {
    int count = 0;

    for (int i = 100; i <= 999; ++i) {
        ////////////////////////////////////
        int digit1 = i / 100;       // Сотни
        int digit2 = (i / 10) % 10; // Десятки
        int digit3 = i % 10;        // Единицы
        ////////////////////////////////////
        if ((digit1 != digit2) && (digit1 != digit3) && (digit2 != digit3)) {
            // У числа все цифры разные
            count++;
        }
    }
    return count;
}

int removalOfThreesAndSixes(int number) {
    ////////////////////////////////////
    std::string numStr = std::to_string(number);
    ////////////////////////////////////
    for (size_t i = 0; i < numStr.size(); ++i) {
        if (numStr[i] == '3' || numStr[i] == '6') {
            numStr.erase(i, 1);
            --i;
        }
    }

    return std::stoi(numStr);
}

void mathTrick(int A) {
    std::cout << "Числа B, для которых " << A << " делится на B*B и не делится на B*B*B:" << std::endl;
    for (int i = A - 1; i > 1; i--)
    {
        int B = i;
        if ((A % (B * B) == 0) && (A % (B * B * B) != 0))
        {
            std::cout << B << std::endl;
        }
    }
}

int sumOfDigitsCube(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum * sum * sum;
}

void mathematicalMagic(int number) {
    std::cout << "Числа, на которые " << number << " делится без остатка:" << std::endl;
    for (int i = 1; i <= number; ++i) {
        if (number % i == 0) {
            std::cout << i << std::endl;
        }
    }
}

void gypsyFocus(int num1, int num2) {
    int gcd = 1;
    std::cout << "Числа, на которые оба введенных числа делятся без остатка:" << std::endl;
    for (int i = 2; i <= std::min(num1, num2); ++i) {
        if (num1 % i == 0 && num2 % i == 0) {
            gcd = i;
        }
    }
    for (int i = 1; i <= gcd; ++i) {
        if (gcd % i == 0) {
            std::cout << i << std::endl;
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
        std::cout << "Введите целое число от 1 до 7: ";
        while (open == false)
        {
            /*
            while (!(std::cin >> usernum) || std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введено некоректное значения. Спробуйте ёще раз: ";
            }
            */
            usernum = getUserInput();
            if (usernum == 1) {
                int result = countNumbersWithSameDigits();
                std::cout << "Количество чисел с двумя одинаковыми цифрами: " << result << std::endl;
                open = true;
            }
            else if (usernum == 2) {
                int result = countNumbersWithAllDifferentDigits();
                std::cout << "Количество чисел с разными цифрами: " << result << std::endl;
                open = true;
            }
            else if (usernum == 3) {
                ////////////////////////////////////
                int userInput;
                ////////////////////////////////////
                std::cout << "Введите целое число: ";
                userInput = getUserInput();
                ////////////////////////////////////
                int result = removalOfThreesAndSixes(userInput);
                std::cout << "Результат после удаления цифр 3 и 6: " << result << std::endl;
                open = true;
            }
            else if (usernum == 4) {
                ////////////////////////////////////
                int userInput;
                ////////////////////////////////////
                std::cout << "Введите целое число: ";
                userInput = getUserInput();
                ////////////////////////////////////
                mathTrick(userInput);
                open = true;
            }
            else if (usernum == 5) {
                ////////////////////////////////////
                int userInput;
                int sumCube;
                ////////////////////////////////////
                std::cout << "Введите целое число: ";
                userInput = getUserInput();
                sumCube = sumOfDigitsCube(userInput);
                ////////////////////////////////////
                //std::cout << sumCube << std::endl;
                //std::cout << pow(userInput, 2) << std::endl;
                ////////////////////////////////////
                if (sumCube == pow(userInput, 2)) {
                    std::cout << "Куб суммы цифр числа равен A * A." << std::endl;
                }
                else {
                    std::cout << "Куб суммы цифр числа не равен A * A." << std::endl;
                }
                ////////////////////////////////////
                open = true;
            }
            else if (usernum == 6) {
                ////////////////////////////////////
                int userInput;
                ////////////////////////////////////
                std::cout << "Введите целое число: ";
                userInput = getUserInput();
                ////////////////////////////////////
                mathematicalMagic(userInput);
                open = true;
            }
            else if (usernum == 7) {
                ////////////////////////////////////
                int userInput1;
                int userInput2;
                ////////////////////////////////////
                std::cout << "Введите первое целое число: ";
                userInput1 = getUserInput();
                std::cout << "Введите второе целое число: ";
                userInput2 = getUserInput();
                ////////////////////////////////////
                gypsyFocus(userInput1, userInput2);
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