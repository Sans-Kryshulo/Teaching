#include "Passenger.h"

Passenger::Passenger() {
    arrivalTime = std::chrono::system_clock::now();
}

Passenger::Passenger(const Passenger& other) : arrivalTime(other.arrivalTime) {}

Passenger::Passenger(Passenger&& other) noexcept : arrivalTime(other.arrivalTime) {
    other.arrivalTime = std::chrono::system_clock::time_point();
}

Passenger& Passenger::operator=(const Passenger& other) {
    if (this != &other) {
        arrivalTime = other.arrivalTime;
    }
    return *this;
}

Passenger& Passenger::operator=(Passenger&& other) noexcept {
    if (this != &other) {
        arrivalTime = other.arrivalTime;
        other.arrivalTime = std::chrono::system_clock::time_point();
    }
    return *this;
}
