#ifndef MINIBUS_H
#define MINIBUS_H

#include <cstdlib>

class Minibus {
public:
    Minibus();
    Minibus(const Minibus& other) = default;
    Minibus(Minibus&& other) noexcept;
    Minibus& operator=(const Minibus& other) = default;
    Minibus& operator=(Minibus&& other) noexcept;
    ~Minibus() = default;

    int freeSeats;
};

#endif 
