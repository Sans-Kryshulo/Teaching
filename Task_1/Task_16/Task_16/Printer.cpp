#include "Printer.h"
#include <iostream>

Printer::Printer() {}

void Printer::addPrintRequest(const PrintRequest& request) {
    std::unique_lock<std::mutex> lock(mtx);
    printQueue.push(request);
    cv.notify_one(); // ���������� ��������� ����� � ����� �������
}

void Printer::print() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return !printQueue.empty(); }); // ����, ���� ������� �� ������ ��������

        if (printQueue.empty()) { // ���� ������� �����, ������� �� �����
            break;
        }

        PrintRequest request = std::move(printQueue.front());
        printQueue.pop();
        lock.unlock(); // ������������ ������� ��� ������ ���������

        // �������� ������
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // ������� ���������� � ������
        std::cout << "Printing for user " << request.getUser() << " with priority " << request.getPriority() << " at time "
            << std::chrono::system_clock::to_time_t(request.getTime()) << std::endl;
    }
}

void Printer::printStatistics() {
    std::unique_lock<std::mutex> lock(mtx);
    while (!printQueue.empty()) {
        PrintRequest request = std::move(printQueue.front());
        printQueue.pop();
        std::cout << "Print request discarded for user " << request.getUser() << " with priority " << request.getPriority()
            << " at time " << std::chrono::system_clock::to_time_t(request.getTime()) << std::endl;
    }
}
