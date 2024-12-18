#include "Stop.h"

Stop::Stop(double avgPassengerInterval, double avgMinibusInterval, bool isTerminal)
    : avgPassengerInterval(avgPassengerInterval), avgMinibusInterval(avgMinibusInterval), isTerminal(isTerminal),
    passengerDistribution(1.0 / avgPassengerInterval), minibusDistribution(1.0 / avgMinibusInterval) {}

Stop::Stop(const Stop& other)
    : passengers(other.passengers), avgPassengerInterval(other.avgPassengerInterval),
    avgMinibusInterval(other.avgMinibusInterval), isTerminal(other.isTerminal),
    passengerDistribution(other.passengerDistribution), minibusDistribution(other.minibusDistribution) {}

Stop::Stop(Stop&& other) noexcept
    : passengers(std::move(other.passengers)), avgPassengerInterval(other.avgPassengerInterval),
    avgMinibusInterval(other.avgMinibusInterval), isTerminal(other.isTerminal),
    passengerDistribution(std::move(other.passengerDistribution)),
    minibusDistribution(std::move(other.minibusDistribution)) {}

Stop& Stop::operator=(const Stop& other) {
    if (this != &other) {
        passengers = other.passengers;
        avgPassengerInterval = other.avgPassengerInterval;
        avgMinibusInterval = other.avgMinibusInterval;
        isTerminal = other.isTerminal;
        passengerDistribution = other.passengerDistribution;
        minibusDistribution = other.minibusDistribution;
    }
    return *this;
}

Stop& Stop::operator=(Stop&& other) noexcept {
    if (this != &other) {
        passengers = std::move(other.passengers);
        avgPassengerInterval = other.avgPassengerInterval;
        avgMinibusInterval = other.avgMinibusInterval;
        isTerminal = other.isTerminal;
        passengerDistribution = std::move(other.passengerDistribution);
        minibusDistribution = std::move(other.minibusDistribution);
    }
    return *this;
}

void Stop::simulate(int maxPassengers, int simulationTime) {
    auto startTime = std::chrono::system_clock::now();
    auto currentTime = startTime;
    double nextPassengerTime = 0.0;
    double nextMinibusTime = 0.0;

    while (std::chrono::duration_cast<std::chrono::minutes>(currentTime - startTime).count() < simulationTime) {
        currentTime = std::chrono::system_clock::now();
        if (nextPassengerTime <= 0.0) {
            nextPassengerTime = passengerDistribution(generator);
        }

        if (nextMinibusTime <= 0.0) {
            nextMinibusTime = minibusDistribution(generator);
        }

        if (nextPassengerTime <= nextMinibusTime) {
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(nextPassengerTime * 1000)));
            passengers.push(Passenger());
            std::cout << "Passenger arrived. Total passengers: " << passengers.size() << std::endl;
            nextMinibusTime -= nextPassengerTime;
            nextPassengerTime = 0.0;
        }
        else {
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(nextMinibusTime * 1000)));
            Minibus minibus;
            int seats = minibus.freeSeats;
            std::cout << "Minibus arrived with " << seats << " free seats." << std::endl;

            while (!passengers.empty() && seats > 0) {
                passengers.pop();
                seats--;
            }
            std::cout << "Passengers left: " << passengers.size() << std::endl;
            nextPassengerTime -= nextMinibusTime;
            nextMinibusTime = 0.0;
        }

        if (passengers.size() > maxPassengers) {
            std::cout << "Stop overflowed with " << passengers.size() << " passengers." << std::endl;
            break;
        }
    }

    std::cout << "Simulation ended with " << passengers.size() << " passengers remaining." << std::endl;
}
