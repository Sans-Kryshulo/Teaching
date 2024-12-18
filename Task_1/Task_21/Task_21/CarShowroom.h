// CarShowroom.h
#ifndef CARSHOWROOM_H
#define CARSHOWROOM_H

#include "Car.h"
#include <vector>
#include <string>
#include <functional>

class CarShowroom {
private:
    std::vector<Car> cars;

public:
    void AddCar(const Car& car);
    void RemoveCar(const std::string& name);
    void DisplayCars() const;
    void SortCars(std::function<bool(const Car&, const Car&)> compare);
    void FindCarByName(const std::string& name) const;
    void FindCarByYear(int year) const;
};

#endif // CARSHOWROOM_H
