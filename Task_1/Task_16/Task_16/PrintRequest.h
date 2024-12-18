#ifndef PRINTREQUEST_H
#define PRINTREQUEST_H

#include <string>
#include <chrono>

class PrintRequest {
private:
    std::string user; // Пользователь, отправивший запрос
    std::chrono::system_clock::time_point time; // Время запроса
    int priority; // Приоритет запроса

public:
    PrintRequest(const std::string& user, int priority);
    PrintRequest(const PrintRequest& other); // Конструктор копирования
    PrintRequest(PrintRequest&& other) noexcept = default; // Конструктор переноса
    ~PrintRequest() = default;

    PrintRequest& operator=(const PrintRequest& other); // Оператор присваивания
    PrintRequest& operator=(PrintRequest&& other) noexcept = default; // Оператор присваивания переноса

    const std::string& getUser() const;
    const std::chrono::system_clock::time_point& getTime() const;
    int getPriority() const;
};

#endif
