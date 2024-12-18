// Car.cpp
#include "Car.h"
#include <iostream>

Car::Car(const std::string& name, int year, double engineVolume, double price)
    : name(name), year(year), engineVolume(engineVolume), price(price) {}

std::string Car::GetName() const {
    return name;
}

int Car::GetYear() const {
    return year;
}

double Car::GetEngineVolume() const {
    return engineVolume;
}

double Car::GetPrice() const {
    return price;
}

void Car::PrintInfo() const {
    std::cout << "Car: " << name << ", Year: " << year
        << ", Engine Volume: " << engineVolume << "L, Price: $" << price << std::endl;
}

bool Car::operator<(const Car& other) const {
    return name < other.name;
}

bool Car::operator>(const Car& other) const {
    return name > other.name;
}
