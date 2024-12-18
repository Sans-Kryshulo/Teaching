#ifndef PRINTER_H
#define PRINTER_H

#include "PrintRequest.h"
#include <queue>
#include <mutex>
#include <condition_variable>

class Printer {
private:
    std::queue<PrintRequest> printQueue; // Очередь печати
    std::mutex mtx; // Мьютекс для синхронизации доступа к очереди
    std::condition_variable cv; // Условная переменная для ожидания новых запросов

public:
    Printer();
    Printer(const Printer& other) = delete; // Запрещаем копирование
    Printer(Printer&& other) noexcept = default; // Конструктор переноса
    ~Printer() = default;

    Printer& operator=(const Printer& other) = delete; // Запрещаем копирование
    Printer& operator=(Printer&& other) noexcept = default; // Оператор присваивания переноса

    void addPrintRequest(const PrintRequest& request);
    void print();
    void printStatistics();
};

#endif
