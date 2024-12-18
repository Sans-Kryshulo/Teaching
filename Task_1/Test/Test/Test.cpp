#include <iostream>
#include <cstring>

class String {
private:
    static const int defaultSize = 80;
    char* data;
    int size;

public:
    // Конструкторы
    String() : data(new char[defaultSize]), size(defaultSize) {}
    String(int size) : data(new char[size]), size(size) {}
    String(const char* str) : data(nullptr), size(0) {
        int len = strlen(str) + 1;
        data = new char[len];
        size = len;
        strcpy_s(data, len, str);
    }

    // Деструктор
    ~String() {
        delete[] data;
    }

    // Методы ввода и вывода строк
    void input() {
        std::cout << "Введите текст: ";
        std::cin.getline(data, size);
    }

    void output() const {
        std::cout << "Текст: " << data << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    String str1; // Конструктор по умолчанию
    str1.input();
    str1.output();

    String str2(100); // Конструктор для произвольного размера
    str2.input();
    str2.output();

    String str3("Ого, я крут!"); // Конструктор с инициализацией
    str3.output();

    return 0;
}
