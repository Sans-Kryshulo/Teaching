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
//////////////////////1///////////////////////
class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Конструкторы
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}

    // Функция для ввода данных
    void input() {
        std::cout << "Введите числитель: ";
        std::cin >> numerator;
        std::cout << "Введите знаменатель: ";
        std::cin >> denominator;
    }

    // Функции-члены для выполнения арифметических операций
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    // Функция для вывода дроби
    void display() const {
        std::cout << numerator << "/" << denominator;
    }
};
//////////////////////2///////////////////////
class Contact {
private:
    std::string* fullName;
    std::string homePhone;
    std::string workPhone;
    std::string mobilePhone;
    std::string additionalInfo;

public:
    // Конструктор
    Contact(const std::string& name, const std::string& home, const std::string& work,
        const std::string& mobile, const std::string& additional)
        : homePhone(home), workPhone(work), mobilePhone(mobile), additionalInfo(additional) {
        fullName = new std::string(name);
    }

    // Деструктор для освобождения памяти
    ~Contact() {
        delete fullName;
    }

    // Inline-функции-члены для доступа к данным
    const std::string& getFullName() const { return *fullName; }
    const std::string& getHomePhone() const { return homePhone; }
    const std::string& getWorkPhone() const { return workPhone; }
    const std::string& getMobilePhone() const { return mobilePhone; }
    const std::string& getAdditionalInfo() const { return additionalInfo; }

    // Функция для удаления контакта
    void deleteContact() {
        delete this;
    }
};
int main() {
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
                Fraction fraction1, fraction2, result;
                //////////////////////////////////////////////
                std::cout << "Введите данные для первой дроби:\n";
                fraction1.input();
                std::cout << "--------------------------------\n";
                std::cout << "Введите данные для второй дроби:\n";
                fraction2.input();
                std::cout << "--------------------------------\n";
                //////////////////////////////////////////////
                result = fraction1 + fraction2;
                std::cout << "Сумма: ";
                result.display();
                std::cout << std::endl;
                //////////////////////////////////////////////
                result = fraction1 - fraction2;
                std::cout << "Разность: ";
                result.display();
                std::cout << std::endl;
                //////////////////////////////////////////////
                result = fraction1 * fraction2;
                std::cout << "Произведение: ";
                result.display();
                std::cout << std::endl;
                //////////////////////////////////////////////
                result = fraction1 / fraction2;
                std::cout << "Деление: ";
                result.display();
                std::cout << std::endl;
                open = true;
                std::cout << "--------------------------------\n";
            }
            else if (usernum == 2) {
                Contact* contacts[100];
                int contactCount = 0;
                std::string FIO;
                std::string num_home;
                std::string num_work;
                std::string num_mobile;
                std::string info;
                std::string searchFIO;
                int usernum_2;
                int indexToDelete;
                do {
                    std::cout << "1. Добавить запись\n"
                        << "2. Удалить запись по индексу\n"
                        << "3. Выборка данных по фамилии\n"
                        << "4. Вывести весь справочник\n"
                        << "0. Выход\n"
                        << "Выберите действие: ";
                    usernum_2 = getUserInput();
                    /*
                    contacts[contactCount++] = new Contact("Иван Иванов", "123-456", "789-012", "345-678", "Друг");
                    contacts[contactCount++] = new Contact("Петр Петров", "111-222", "333-444", "555-666", "Коллега");
                    contacts[contactCount++] = new Contact("Сидор Сидоров", "777-888", "999-000", "123-456", "Брат");
                    */
                    std::cout << "-----------------------------" << std::endl;
                    switch (usernum_2) {
                    case 1:
                        std::cout << "Введите ФИО: ";
                        std::getline(std::cin >> std::ws, FIO);
                        std::cout << "Введите домашний телефон: ";
                        std::cin >> num_home;
                        std::cout << "Введите рабочий телефон: ";
                        std::cin >> num_work;
                        std::cout << "Введите мобильный телефон: ";
                        std::cin >> num_mobile;
                        std::cout << "Введите дополнительную информацию: ";
                        std::getline(std::cin >> std::ws, info);
                        contacts[contactCount++] = new Contact(FIO, num_home, num_work, num_mobile, info);
                        std::cout << "-----------------------------" << std::endl;
                        break;
                    case 2:
                        std::cout << "Введите индекс для удаления: ";
                        indexToDelete = getUserInput() - 1;
                        if (indexToDelete >= 0 && indexToDelete < contactCount) {
                            std::cout << "Удаляем контакт: " << contacts[indexToDelete]->getFullName() << std::endl;
                            contacts[indexToDelete]->deleteContact();
                            for (int i = indexToDelete; i < contactCount - 1; ++i) {
                                contacts[i] = contacts[i + 1];
                            }
                            --contactCount;
                        }
                        else {
                            std::cout << "Неверный индекс для удаления контакта." << std::endl;
                        }
                        std::cout << "-----------------------------" << std::endl;
                        break;
                    case 3:
                        std::cout << "Введите ФИО для поиска: ";
                        //searchFIO = "Иван Сиванов";
                        std::getline(std::cin >> std::ws, searchFIO);
                        for (int i = 0; i < contactCount; ++i) {
                            if (contacts[i]->getFullName() == searchFIO) {
                                std::cout << "Контакт найден!\n";
                                std::cout << "ФИО: " << contacts[i]->getFullName() << std::endl;
                                std::cout << "Домашний телефон: " << contacts[i]->getHomePhone() << std::endl;
                                std::cout << "Рабочий телефон: " << contacts[i]->getWorkPhone() << std::endl;
                                std::cout << "Мобильный телефон: " << contacts[i]->getMobilePhone() << std::endl;
                                std::cout << "Дополнительная информация: " << contacts[i]->getAdditionalInfo() << std::endl;
                                break;
                            } 
                            else {
                                std::cout << "Контакт не найден!\n";
                            }
                        }  
                        std::cout << "-----------------------------" << std::endl;
                        break;
                    case 4:
                        std::cout << "Список всех абонентов:\n";
                        for (int i = 0; i < contactCount; ++i) {
                            std::cout << "Индекс: " << i+1 << std::endl;
                            std::cout << "ФИО: " << contacts[i]->getFullName() << std::endl;
                            std::cout << "Домашний телефон: " << contacts[i]->getHomePhone() << std::endl;
                            std::cout << "Рабочий телефон: " << contacts[i]->getWorkPhone() << std::endl;
                            std::cout << "Мобильный телефон: " << contacts[i]->getMobilePhone() << std::endl;
                            std::cout << "Дополнительная информация: " << contacts[i]->getAdditionalInfo() << std::endl;
                            std::cout << std::endl;
                        }
                        std::cout << "-----------------------------" << std::endl;
                        break;
                    case 0:
                        std::cout << "Выход из программы." << std::endl;
                        std::cout << "-----------------------------" << std::endl;
                        break;
                    default:
                        std::cout << "Неверный выбор. Повторите ввод." << std::endl;
                    }
                } while (usernum_2 != 0);
                //////////////////////////////////////////////
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