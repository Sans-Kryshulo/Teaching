#include "Minibus.h"

Minibus::Minibus() {
    freeSeats = rand() % 20 + 1; 
}

Minibus::Minibus(Minibus&& other) noexcept : freeSeats(other.freeSeats) {
    other.freeSeats = 0;
}

Minibus& Minibus::operator=(Minibus&& other) noexcept {
    if (this != &other) {
        freeSeats = other.freeSeats;
        other.freeSeats = 0;
    }
    return *this;
}
