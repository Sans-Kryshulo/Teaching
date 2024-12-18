#include <iostream>
#include <vector>
#include <sstream>
#include "Reservoir.h"
#include "House.h"
#include "String.h"
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

void addReservoir(std::vector<Reservoir>& reservoirs) {
    std::string name;
    double width, length, maxDepth;
    std::cout << "Введите название водоема: ";
    std::cin >> name;
    std::cout << "Введите ширину водоема (m): ";
    std::cin >> width;
    std::cout << "Введите длину водоема (m): ";
    std::cin >> length;
    std::cout << "Введите максимальную глубину водоема: (m) ";
    std::cin >> maxDepth;

    reservoirs.push_back(Reservoir(name, width, length, maxDepth));
}

void removeReservoir(std::vector<Reservoir>& reservoirs, int index) {
    if (index >= 0 && index < reservoirs.size()) {
        reservoirs.erase(reservoirs.begin() + index);
        std::cout << "Водоем удален." << std::endl;
    }
    else {
        std::cout << "Неверный индекс." << std::endl;
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
        std::cout << "Введите целое число от 1 до 3: ";
        while (open == false)
        {
            usernum = getUserInput(); 
            if (usernum == 1) {
                House house("Улица Пушкина, дом Колотушкина");

                house.addApartment(101);
                house.addApartment(102);
                house.addApartment(103);

                house.addPersonToApartment(101, "Иванов Иван Иванович");
                house.addPersonToApartment(101, "Петров Петр Петрович");
                house.addPersonToApartment(102, "Сидоров Сидор Сидорович");

                house.print();

                open = true;
            }
            else if (usernum == 2) {
                int numDelete;
                std::vector<Reservoir> reservoirs;

                addReservoir(reservoirs);
                addReservoir(reservoirs);

                std::cout << "Водоем:" << std::endl;
                for (int i = 0; i < reservoirs.size(); ++i) {
                    std::cout << i + 1 << ". Имя: " << reservoirs[i].getName() << ", Площадь поверхности (m3): " << reservoirs[i].surfaceArea() << std::endl;
                }
                std::cout << "Введите номер водоема, которий хотите удалить: ";
                std::cin >> numDelete;
                removeReservoir(reservoirs, numDelete - 1);

                std::cout << "Остальные водоеми:" << std::endl;
                for (int i = 0; i < reservoirs.size(); ++i) {
                    std::cout << i + 1 << ". Имя: " << reservoirs[i].getName() << ", Площадь поверхности (m3): " << reservoirs[i].surfaceArea() << std::endl;
                }

                open = true;
            }
            else if (usernum == 3) {

                String str1; // Конструктор по умолчанию
                str1.input();
                str1.output();

                String str2(100); // Конструктор для произвольного размера
                str2.input();
                str2.output();

                String str3("Hello, world!"); // Конструктор с инициализацией
                str3.output();
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