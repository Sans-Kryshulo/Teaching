#ifndef STOP_H
#define STOP_H

#include "Passenger.h"
#include "Minibus.h"
#include <queue>
#include <chrono>
#include <random>
#include <iostream>
#include <thread>

class Stop {
public:
    Stop(double avgPassengerInterval, double avgMinibusInterval, bool isTerminal);
    Stop(const Stop& other);
    Stop(Stop&& other) noexcept;
    Stop& operator=(const Stop& other);
    Stop& operator=(Stop&& other) noexcept;
    ~Stop() = default;

    void simulate(int maxPassengers, int simulationTime);

private:
    std::queue<Passenger> passengers;
    double avgPassengerInterval;
    double avgMinibusInterval;
    bool isTerminal;

    std::default_random_engine generator;
    std::exponential_distribution<double> passengerDistribution;
    std::exponential_distribution<double> minibusDistribution;
};

#endif
