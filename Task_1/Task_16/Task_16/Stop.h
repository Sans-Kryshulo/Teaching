#ifndef STOP_H
#define STOP_H

#include <vector>
#include "Passenger.h"

class Stop {
private:
    std::vector<Passenger> passengers; // Пассажиры на остановке
    int averageTimePassenger; // Среднее время между появлениями пассажиров
    int averageTimeBus; // Среднее время между прибытиями маршруток
    bool isTerminal; // Тип остановки (конечная или нет)

public:
    Stop(int averageTimePassenger, int averageTimeBus, bool isTerminal);
    Stop(const Stop& other) = delete;
    Stop(Stop&& other) noexcept = default;
    ~Stop() = default;

    Stop& operator=(const Stop& other) = delete;
    Stop& operator=(Stop&& other) noexcept = default;

    void addPassenger(Passenger&& passenger);
    int getNumPassengers() const;
    bool isFull() const;
    Passenger popPassenger();
};

#endif
