#include "Stop.h"
#include <stdexcept>

Stop::Stop(int averageTimePassenger, int averageTimeBus, bool isTerminal)
    : averageTimePassenger(averageTimePassenger), averageTimeBus(averageTimeBus), isTerminal(isTerminal) {}

void Stop::addPassenger(Passenger&& passenger) {
    passengers.push_back(std::move(passenger));
}

int Stop::getNumPassengers() const {
    return passengers.size();
}

bool Stop::isFull() const {
    return passengers.size() >= 10;
}
Passenger Stop::popPassenger() {
    if (!passengers.empty()) {
        Passenger passenger = std::move(passengers.back());
        passengers.pop_back();
        return passenger;
    }
    else {
        throw std::runtime_error("Error: Trying to pop passenger from an empty stop");
    }
}
