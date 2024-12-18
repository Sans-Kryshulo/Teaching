#ifndef PASSENGER_H
#define PASSENGER_H

#include <chrono>

class Passenger {
public:
    Passenger();
    Passenger(const Passenger& other);
    Passenger(Passenger&& other) noexcept;
    Passenger& operator=(const Passenger& other);
    Passenger& operator=(Passenger&& other) noexcept;
    ~Passenger() = default;

    std::chrono::system_clock::time_point arrivalTime;
};

#endif 
