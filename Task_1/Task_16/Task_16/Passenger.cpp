#include "Passenger.h"

Passenger::Passenger(int timeArrival) : timeArrival(timeArrival) {}

int Passenger::getTimeArrival() const {
    return timeArrival;
}
