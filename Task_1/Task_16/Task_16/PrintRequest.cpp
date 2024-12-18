#include "PrintRequest.h"

PrintRequest::PrintRequest(const std::string& user, int priority) : user(user), priority(priority) {
    time = std::chrono::system_clock::now();
}

PrintRequest::PrintRequest(const PrintRequest& other)
    : user(other.user), time(other.time), priority(other.priority) {}

const std::string& PrintRequest::getUser() const {
    return user;
}

const std::chrono::system_clock::time_point& PrintRequest::getTime() const {
    return time;
}

int PrintRequest::getPriority() const {
    return priority;
}
