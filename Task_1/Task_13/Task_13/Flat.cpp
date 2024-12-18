#include "Flat.h"

Flat::Flat() : address(""), area(0.0), price(0.0) {}

Flat::Flat(const std::string& addr, double a, double p) : address(addr), area(a), price(p) {}

bool Flat::operator==(const Flat& other) const {
    return area == other.area;
}

Flat& Flat::operator=(const Flat& other) {
    if (this != &other) {
        address = other.address;
        area = other.area;
        price = other.price;
    }
    return *this;
}

bool Flat::operator>(const Flat& other) const {
    return price > other.price;
}

std::string Flat::getAddress() const {
    return address;
}

double Flat::getArea() const {
    return area;
}

double Flat::getPrice() const {
    return price;
}
