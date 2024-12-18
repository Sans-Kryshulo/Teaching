#include "Printer.h"
#include <iostream>
#include <ctime>

Printer::Printer() {}

void Printer::addRequest(const std::string& user, int priority) {
    PrintRequest request(user, priority);
    queue.addRequest(std::move(request));
}

void Printer::processNextRequest() {
    try {
        PrintRequest request = queue.getNextRequest();
        std::cout << "Printing document for user: " << request.user << " with priority: " << request.priority << std::endl;
        statistics.push({ request.user, std::chrono::system_clock::now() });
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Printer::printStatistics() const {
    std::queue<std::pair<std::string, std::chrono::system_clock::time_point>> temp = statistics;
    while (!temp.empty()) {
        auto stat = temp.front();
        temp.pop();
        std::time_t time = std::chrono::system_clock::to_time_t(stat.second);

        // Safe usage of ctime_s
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &time);

        std::cout << "User: " << stat.first << ", Time: " << buffer;
    }
}