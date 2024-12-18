#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>

struct Date {
    int day;
    int month;
    int year;
};
enum ZodiacSign {
    Aries, Taurus, Gemini, Cancer, Leo, Virgo, Libra, Scorpio, Sagittarius, Capricorn, Aquarius, Pisces
};
const char* zodiacSignNames[] = {
    "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo",
    "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"
};
struct PhoneRecord {
    int id;
    char lastName[50];
    char firstName[50];
    char middleName[50];
    Date birthDate;
    ZodiacSign zodiacSign;
    char phoneNumber[14];
};
///////////////////////////////////////
const int MAX_RECORDS = 100;
PhoneRecord phoneDirectory[MAX_RECORDS];
int currentRecords = 0;
///////////////////////////////////////
Date generateRandomDate() {
    Date date;
    date.day = rand() % 31 + 1;
    date.month = rand() % 12 + 1;
    date.year = rand() % 50 + 1970;
    return date;
}
ZodiacSign determineZodiacSign(const Date& date) {
    if ((date.month == 3 && date.day >= 21) || (date.month == 4 && date.day <= 19)) {
        return Aries;
    }
    else if ((date.month == 4 && date.day >= 20) || (date.month == 5 && date.day <= 20)) {
        return Taurus;
    }
    else if ((date.month == 5 && date.day >= 21) || (date.month == 6 && date.day <= 20)) {
        return Gemini;
    }
    else if ((date.month == 6 && date.day >= 21) || (date.month == 7 && date.day <= 22)) {
        return Cancer;
    }
    else if ((date.month == 7 && date.day >= 23) || (date.month == 8 && date.day <= 22)) {
        return Leo;
    }
    else if ((date.month == 8 && date.day >= 23) || (date.month == 9 && date.day <= 22)) {
        return Virgo;
    }
    else if ((date.month == 9 && date.day >= 23) || (date.month == 10 && date.day <= 22)) {
        return Libra;
    }
    else if ((date.month == 10 && date.day >= 23) || (date.month == 11 && date.day <= 21)) {
        return Scorpio;
    }
    else if ((date.month == 11 && date.day >= 22) || (date.month == 12 && date.day <= 21)) {
        return Sagittarius;
    }
    else if ((date.month == 12 && date.day >= 22) || (date.month == 1 && date.day <= 19)) {
        return Capricorn;
    }
    else if ((date.month == 1 && date.day >= 20) || (date.month == 2 && date.day <= 18)) {
        return Aquarius;
    }
    else {
        return Pisces;
    }
}
void generateRandomPhoneNumber(char* phoneNumber) {
    phoneNumber[0] = '3';
    phoneNumber[1] = '8';
    phoneNumber[2] = '0';
    for (int i = 3; i < 14; ++i) {
        phoneNumber[i] = '0' + rand() % 10;
    }
    phoneNumber[12] = '\0';
}
bool isValidDate(const Date& date) {
    if (date.day < 1 || date.day > 31 || date.month < 1 || date.month > 12 || date.year < 1900 || date.year > 2100) {
        return false;
    }
    const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxDay = daysInMonth[date.month];
    if (date.month == 2 && ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))) {
        maxDay = 29;
    }
    return date.day <= maxDay;
}
void addRecord() {
    if (currentRecords < MAX_RECORDS) {
        PhoneRecord record;
        record.id = currentRecords + 1;
        std::cout << "Введите фамилию: ";
        std::cin >> record.lastName;
        std::cout << "Введите имя: ";
        std::cin >> record.firstName;
        std::cout << "Введите отчество: ";
        std::cin >> record.middleName;
        do {
            std::cout << "Введите дату рождения (день месяц год): ";
            std::cin >> record.birthDate.day >> record.birthDate.month >> record.birthDate.year;
        } while (!isValidDate(record.birthDate));
        record.zodiacSign = determineZodiacSign(record.birthDate);
        generateRandomPhoneNumber(record.phoneNumber);
        phoneDirectory[currentRecords++] = record;
        std::cout << "Запись успешно добавлена." << std::endl;
    }
    else {
        std::cout << "Телефонный справочник полон." << std::endl;
    }
}
void deleteRecord(int index) {
    if (index >= 0 && index < currentRecords) {
        for (int i = index; i < currentRecords - 1; ++i) {
            phoneDirectory[i] = phoneDirectory[i + 1];
        }
        --currentRecords;
        std::cout << "Запись успешно удалена." << std::endl;
    }
    else {
        std::cout << "Неверный индекс записи." << std::endl;
    }
}
void sortByFullName() {
    std::sort(phoneDirectory, phoneDirectory + currentRecords,
        [](const PhoneRecord& a, const PhoneRecord& b) {
            return strcmp(a.lastName, b.lastName) < 0
                || (strcmp(a.lastName, b.lastName) == 0 && strcmp(a.firstName, b.firstName) < 0)
                || (strcmp(a.lastName, b.lastName) == 0 && strcmp(a.firstName, b.firstName) == 0 && strcmp(a.middleName, b.middleName) < 0);
        });
    std::cout << "Справочник отсортирован по ФИО." << std::endl;
}
void sortByPhoneNumber() {
    std::sort(phoneDirectory, phoneDirectory + currentRecords,
        [](const PhoneRecord& a, const PhoneRecord& b) {
            return strcmp(a.phoneNumber, b.phoneNumber) < 0;
        });
    std::cout << "Справочник отсортирован по номеру телефона." << std::endl;
}
void insertRecordInSortedArray() {
    addRecord();
    sortByFullName();
}
void searchByLastName(const char* lastName) {
    bool found = false;
    for (int i = 0; i < currentRecords; ++i) {
        if (strcmp(phoneDirectory[i].lastName, lastName) == 0) {
            std::cout << "Найдена запись: " << phoneDirectory[i].lastName << " "
                << phoneDirectory[i].firstName << " " << phoneDirectory[i].middleName
                << ", Телефон: " << phoneDirectory[i].phoneNumber << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Запись с фамилией '" << lastName << "' не найдена." << std::endl;
    }
}
void searchByZodiacSign(ZodiacSign searchZodiacSign) {
    bool found = false;
    for (int i = 0; i < currentRecords; ++i) {
        if (phoneDirectory[i].zodiacSign == searchZodiacSign) {
            found = true;
            std::cout << "ID: " << phoneDirectory[i].id << std::endl;
            std::cout << "Фамилия: " << phoneDirectory[i].lastName << std::endl;
            std::cout << "Имя: " << phoneDirectory[i].firstName << std::endl;
            std::cout << "Отчество: " << phoneDirectory[i].middleName << std::endl;
            std::cout << "Дата рождения: " << phoneDirectory[i].birthDate.day << "/"
                << phoneDirectory[i].birthDate.month << "/" << phoneDirectory[i].birthDate.year << std::endl;
            std::cout << "Знак зодиака: " << zodiacSignNames[phoneDirectory[i].zodiacSign] << std::endl;
            std::cout << "Номер телефона: " << phoneDirectory[i].phoneNumber << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }
    }
    if (!found) {
        std::cout << "Записи с данным знаком зодиака не найдены." << std::endl;
    }
}
void displayPhoneDirectory() {
    for (int i = 0; i < currentRecords; ++i) {
        std::cout << "ID: " << phoneDirectory[i].id << std::endl;
        std::cout << "Фамилия: " << phoneDirectory[i].lastName << std::endl;
        std::cout << "Имя: " << phoneDirectory[i].firstName << std::endl;
        std::cout << "Отчество: " << phoneDirectory[i].middleName << std::endl;
        std::cout << "Дата рождения: " << phoneDirectory[i].birthDate.day << "/"
            << phoneDirectory[i].birthDate.month << "/" << phoneDirectory[i].birthDate.year << std::endl;
        std::cout << "Знак зодиака: " << zodiacSignNames[phoneDirectory[i].zodiacSign] << std::endl;
        std::cout << "Номер телефона: " << phoneDirectory[i].phoneNumber << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned>(time(nullptr)));
    int choice;
    do {
        std::cout << "1. Добавить запись\n"
            << "2. Удалить запись по индексу\n"
            << "3. Сортировать по ФИО\n"
            << "4. Сортировать по номеру телефона\n"
            << "5. Вставить новую запись в отсортированный массив\n"
            << "6. Выборка данных по фамилии\n"
            << "7. Выборка данных по знаку зодиака\n"
            << "8. Вывести весь справочник\n"
            << "0. Выход\n"
            << "Выберите действие: ";
        std::cin >> choice;
        std::cout << "-----------------------------" << std::endl;
        switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            int indexToDelete;
            std::cout << "Введите индекс записи для удаления: ";
            std::cin >> indexToDelete;
            indexToDelete--;
            deleteRecord(indexToDelete);
            break;
        case 3:
            sortByFullName();
            break;
        case 4:
            sortByPhoneNumber();
            break;
        case 5:
            insertRecordInSortedArray();
            break;
        case 6:
            char searchLastName[50];
            std::cout << "Введите фамилию для поиска: ";
            std::cin >> searchLastName;
            searchByLastName(searchLastName);
            break;
        case 7:
            int searchZodiacSign;
            std::cout << "Список знаков зодиака:(Aries - 1, Taurus - 2, Gemini - 3, Cancer - 4, Leo - 5, Virgo - 6, Libra - 7, Scorpio - 8, Sagittarius - 9, Capricorn - 10, Aquarius - 11, Pisces - 12)" << std::endl;
            std::cout << "Введите номер знака зодиака для поиска: ";
            std::cin >> searchZodiacSign;
            searchByZodiacSign(static_cast<ZodiacSign>(searchZodiacSign - 1));
            break;
        case 8:
            displayPhoneDirectory();
            break;
        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Повторите ввод." << std::endl;
        }
    } while (choice != 0);

    return 0;
}