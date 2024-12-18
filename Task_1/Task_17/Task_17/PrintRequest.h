#ifndef PRINTREQUEST_H
#define PRINTREQUEST_H

#include <string>
#include <chrono>

class PrintRequest {
public:
    PrintRequest(std::string user, int priority);
    PrintRequest(const PrintRequest& other);
    PrintRequest(PrintRequest&& other) noexcept;
    PrintRequest& operator=(const PrintRequest& other);
    PrintRequest& operator=(PrintRequest&& other) noexcept;
    ~PrintRequest() = default;

    std::string user;
    int priority;
    std::chrono::system_clock::time_point requestTime;
};

#endif // PRINTREQUEST_H
