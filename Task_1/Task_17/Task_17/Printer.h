#ifndef PRINTER_H
#define PRINTER_H

#include "PrinterQueue.h"
#include <queue>
#include <string>

class Printer {
public:
    Printer();
    void addRequest(const std::string& user, int priority);
    void processNextRequest();
    void printStatistics() const;

private:
    PrinterQueue queue;
    std::queue<std::pair<std::string, std::chrono::system_clock::time_point>> statistics;
};

#endif // PRINTER_H
