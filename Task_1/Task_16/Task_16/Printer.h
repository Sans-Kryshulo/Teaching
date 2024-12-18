#ifndef PRINTER_H
#define PRINTER_H

#include "PrintRequest.h"
#include <queue>
#include <mutex>
#include <condition_variable>

class Printer {
private:
    std::queue<PrintRequest> printQueue; // ������� ������
    std::mutex mtx; // ������� ��� ������������� ������� � �������
    std::condition_variable cv; // �������� ���������� ��� �������� ����� ��������

public:
    Printer();
    Printer(const Printer& other) = delete; // ��������� �����������
    Printer(Printer&& other) noexcept = default; // ����������� ��������
    ~Printer() = default;

    Printer& operator=(const Printer& other) = delete; // ��������� �����������
    Printer& operator=(Printer&& other) noexcept = default; // �������� ������������ ��������

    void addPrintRequest(const PrintRequest& request);
    void print();
    void printStatistics();
};

#endif
