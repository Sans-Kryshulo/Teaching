#include "Bus.h"
#include <iostream>

Bus::Bus(int capacity) : capacity(capacity) {}

int Bus::getCapacity() const {
    return capacity;
}

int Bus::getNumPassengers() const {
    return passengers.size();
}

void Bus::addPassenger(Passenger&& passenger) {
    if (passengers.size() < capacity) {
        passengers.push_back(std::move(passenger));
    }
    else {
        std::cerr << "Error: Bus is full\n";
    }
}
