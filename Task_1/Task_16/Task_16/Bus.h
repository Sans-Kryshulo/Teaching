#ifndef BUS_H
#define BUS_H

#include <vector>
#include "Passenger.h"

class Bus {
private:
    int capacity;
    std::vector<Passenger> passengers;

public:
    Bus(int capacity);
    Bus(const Bus& other) = delete;
    Bus(Bus&& other) noexcept = default;
    ~Bus() = default;

    Bus& operator=(const Bus& other) = delete;
    Bus& operator=(Bus&& other) noexcept = default;

    int getCapacity() const;
    int getNumPassengers() const;
    void addPassenger(Passenger&& passenger);
};

#endif

