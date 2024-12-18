// CarShowroom.cpp
#include "CarShowroom.h"
#include <algorithm>
#include <iostream>

void CarShowroom::AddCar(const Car& car) {
    cars.push_back(car);
}

void CarShowroom::RemoveCar(const std::string& name) {
    cars.erase(std::remove_if(cars.begin(), cars.end(),
        [&name](const Car& car) { return car.GetName() == name; }), cars.end());
}

void CarShowroom::DisplayCars() const {
    for (const auto& car : cars) {
        car.PrintInfo();
    }
}

void CarShowroom::SortCars(std::function<bool(const Car&, const Car&)> compare) {
    std::sort(cars.begin(), cars.end(), compare);
}

void CarShowroom::FindCarByName(const std::string& name) const {
    auto it = std::find_if(cars.begin(), cars.end(),
        [&name](const Car& car) { return car.GetName() == name; });
    if (it != cars.end()) {
        it->PrintInfo();
    }
    else {
        std::cout << "Car with name \"" << name << "\" not found." << std::endl;
    }
}

void CarShowroom::FindCarByYear(int year) const {
    auto it = std::find_if(cars.begin(), cars.end(),
        [year](const Car& car) { return car.GetYear() == year; });
    if (it != cars.end()) {
        it->PrintInfo();
    }
    else {
        std::cout << "Car with year " << year << " not found." << std::endl;
    }
}
