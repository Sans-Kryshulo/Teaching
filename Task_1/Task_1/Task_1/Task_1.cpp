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
        std::cout << "Введите целое число: ";
        while (open == false)
        {
            while (!(std::cin >> usernum) || std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введено некоректное значения. Спробуйте ёще раз: ";
            }
            if (usernum == 1) {
                int inputSeconds;
                std::cout << "Введите количество секунд: ";
                std::cin >> inputSeconds;
                int hours = inputSeconds / 3600;
                int minutes = (inputSeconds % 3600) / 60;
                int seconds = inputSeconds % 60;
                std::cout << "Часы: " << hours << ", Минуты: " << minutes << ", Секунды: " << seconds << std::endl;
                open = true;
            } else if (usernum == 2) {
                double inputMoney;
                std::cout << "Введите дробное число: ";
                std::cin >> inputMoney;
                int dollars = static_cast<int>(inputMoney);
                int cents = static_cast<int>((inputMoney - dollars) * 100);
                std::cout << "Долларов: " << dollars << ", Центов: " << cents << std::endl;
                open = true;
            }  else if (usernum == 3) {
                int inputDays;
                std::cout << "Введите количество дней: ";
                std::cin >> inputDays;
                int weeks = inputDays / 7;
                int remainingDays = inputDays % 7;
                std::cout << "Недель: " << weeks << ", Дней: " << remainingDays << std::endl;
                open = true;
            }  else if (usernum == 4) {
                double distanceMeters, inputTime, speed;
                int minutes, seconds, time;
                std::cout << "Введите длину дистанции (метры): ";
                std::cin >> distanceMeters;
                std::cout << "Введите время (мин.сек): ";
                std::cin >> inputTime;
                minutes = static_cast<int>(inputTime);
                seconds = (inputTime - minutes) * 100;
                time = (minutes * 60) + seconds;
                speed = distanceMeters / time * 3.6;
                std::cout << "Дистанция: " << distanceMeters << " м" << std::endl;
                std::cout << "Время: " << minutes << " мин " << seconds << " сек = " << time << " сек" << std::endl;
                std::cout << "Вы бежали со скоростью " << speed << " км/ч" << std::endl;
                open = true;
            }  else if (usernum == 5) {
                double initialDeposit, annualInterestRate;
                std::cout << "Введите сумму денежного вклада в евро: ";
                std::cin >> initialDeposit;
                std::cout << "Введите процент годовых, выплачиваемый банком: ";
                std::cin >> annualInterestRate;
                double monthlyInterestRate = annualInterestRate / 100.0 / 12.0;
                double monthlyPayment = initialDeposit * monthlyInterestRate;
                std::cout << "Сумма, выплачиваемая банком вкладчику каждый месяц: " << monthlyPayment << " евро" << std::endl;
                open = true;
            }  else {
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
            } else if (userexit == "y" || userexit == "Y") {
                ExitBool = false;
                exit = true;
            } else {
                ExitBool = false;
                exit = false;
                std::cout << "Введено некоректное значения. Спробуйте ёще раз. \n";
            }
        }
    }
    return 0;
}