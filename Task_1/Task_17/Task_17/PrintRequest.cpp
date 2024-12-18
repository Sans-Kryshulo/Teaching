#include "PrintRequest.h"

PrintRequest::PrintRequest(std::string user, int priority)
    : user(std::move(user)), priority(priority), requestTime(std::chrono::system_clock::now()) {}

PrintRequest::PrintRequest(const PrintRequest& other)
    : user(other.user), priority(other.priority), requestTime(other.requestTime) {}

PrintRequest::PrintRequest(PrintRequest&& other) noexcept
    : user(std::move(other.user)), priority(other.priority), requestTime(other.requestTime) {}

PrintRequest& PrintRequest::operator=(const PrintRequest& other) {
    if (this != &other) {
        user = other.user;
        priority = other.priority;
        requestTime = other.requestTime;
    }
    return *this;
}

PrintRequest& PrintRequest::operator=(PrintRequest&& other) noexcept {
    if (this != &other) {
        user = std::move(other.user);
        priority = other.priority;
        requestTime = other.requestTime;
    }
    return *this;
}
