#include <iostream>
#include <algorithm>
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
//Структура книг
struct Book {
    std::string title;
    std::string author;
    int year;
    std::string genre;
};
//Печать информации о книге
void printBook(const Book& book) {
    std::cout << "Название: " << book.title << std::endl;
    std::cout << "Автор: " << book.author << std::endl;
    std::cout << "Год выпуска: " << book.year << std::endl;
    std::cout << "Жанр: " << book.genre << std::endl << std::endl;
}
//Печать всех книг в массиве
void printAllBooks(const Book books[], int MAX_BOOKS) {
    std::cout << "Список книг:" << std::endl;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        std::cout << "#" << i + 1 << " -----------------------" << std::endl;
        printBook(books[i]);
    }
    std::cout << "-----------------------" << std::endl;
}
//Редактирования информации о книге
void editBook(Book& book) {
    std::cout << "Введите новое название книги: ";
    std::getline(std::cin >> std::ws, book.title);

    std::cout << "Введите нового автора: ";
    std::getline(std::cin >> std::ws, book.author);

    std::cout << "Введите новый год выпуска: ";
    std::cin >> book.year;

    std::cout << "Введите новый жанр: ";
    std::getline(std::cin >> std::ws, book.genre);

    std::cout << "Информация о книге успешно отредактирована." << std::endl;
}
//Поиск книг по автору
void searchByAuthor(const Book books[], const std::string& author, int MAX_BOOKS) {
    std::cout << "Результаты поиска по автору \"" << author << "\":" << std::endl;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (books[i].author == author) {
            printBook(books[i]);
        }
    }
}
//Поиск книги по названию
void searchByTitle(const Book books[], const std::string& title, int MAX_BOOKS) {
    std::cout << "Результаты поиска по названию \"" << title << "\":" << std::endl;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (books[i].title == title) {
            printBook(books[i]);
            return;
        }
    }
    std::cout << "Книга с таким названием не найдена." << std::endl;
}
//Сортировка массива книг по названию
void sortByTitle(Book books[], int MAX_BOOKS) {
    std::sort(books, books + MAX_BOOKS, [](const Book& a, const Book& b) {
        return a.title < b.title;
        });
    std::cout << "Массив книг отсортирован по названию." << std::endl;
}
//Сортировка массива книг по автору
void sortByAuthor(Book books[], int MAX_BOOKS) {
    std::sort(books, books + MAX_BOOKS, [](const Book& a, const Book& b) {
        return a.author < b.author;
        });
    std::cout << "Массив книг отсортирован по автору." << std::endl;
}
//Сортировка массива книг по году выпуска
void sortByYear(Book books[], int MAX_BOOKS) {
    std::sort(books, books + MAX_BOOKS, [](const Book& a, const Book& b) {
        return a.year < b.year;
        });
    std::cout << "Массив книг отсортирован по году выпуска." << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int MAX_BOOKS = 10;
    Book library[MAX_BOOKS] = {
        {"The Hobbit", "John Ronald Reuel Tolkien", 1937, "fantasy"},
        {"And There Were None", "Agatha Christie", 1939, "detective"},
        {"Harry Potter and the Philosopher's Stone", "Joan Rowling", 1997, "fantasy"},
        {"The Little Prince", "Antoine de Saint-Exupéry", 1943, "fairy tale-parable"},
        {"The Lord of the Rings", "John Ronald Reuel Tolkien", 1954, "fantasy"},
        {"A Tale of Two Cities", "Charles Dickens", 1859, "historical novel"},
        {"Don Quixote", "Miguel de Cervantes", 1605, "novel"},
        {"Quotes from Chairman Mao Zedong", "Mao Zedong", 1964, "quotation book"},
        {"Koran", "Collective of Authors", 610, "religious literature"},
        {"Bible", "Collective of authors", 0, "religious literature"}
    };

    int choice;

    do {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Редактировать книгу" << std::endl;
        std::cout << "2. Печать всех книг" << std::endl;
        std::cout << "3. Поиск книг по автору" << std::endl;
        std::cout << "4. Поиск книги по названию" << std::endl;
        std::cout << "5. Сортировка по названию" << std::endl;
        std::cout << "6. Сортировка по автору" << std::endl;
        std::cout << "7. Сортировка по году выпуска" << std::endl;
        std::cout << "0. Выход" << std::endl;

        std::cout << "Ваш выбор: ";
        choice = getUserInput();

        switch (choice) {
        case 1: {
            int bookIndex;
            std::cout << "Введите номер книги для редактирования: ";
            bookIndex = getUserInput();

            if (bookIndex >= 1 && bookIndex <= MAX_BOOKS) {
                editBook(library[bookIndex - 1]);
            }
            else {
                std::cout << "Некорректный номер книги." << std::endl;
            }
            break;
        }
        case 2:
            printAllBooks(library, MAX_BOOKS);
            break;
        case 3: {
            std::string author;
            std::cout << "Введите автора для поиска: ";
            std::getline(std::cin >> std::ws, author);
            searchByAuthor(library, author, MAX_BOOKS);
            break;
        }
        case 4: {
            std::string title;
            std::cout << "Введите название для поиска: ";
            std::getline(std::cin >> std::ws, title);
            searchByTitle(library, title, MAX_BOOKS);
            break;
        }
        case 5:
            sortByTitle(library, MAX_BOOKS);
            break;
        case 6:
            sortByAuthor(library, MAX_BOOKS);
            break;
        case 7:
            sortByYear(library, MAX_BOOKS);
            break;
        case 0:
            std::cout << "Программа завершена." << std::endl;
            break;
        default:
            std::cout << "Некорректный выбор. Повторите попытку." << std::endl;
            break;
        }

    } while (choice != 0);

    return 0;
}