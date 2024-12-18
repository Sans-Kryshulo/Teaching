#include "Overcoat.h"

Overcoat::Overcoat() : type(""), price(0.0) {}

Overcoat::Overcoat(const std::string& t, double p) : type(t), price(p) {}

bool Overcoat::operator==(const Overcoat& other) const {
    return type == other.type;
}

Overcoat& Overcoat::operator=(const Overcoat& other) {
    if (this != &other) {
        type = other.type;
        price = other.price;
    }
    return *this;
}

bool Overcoat::operator>(const Overcoat& other) const {
    return type == other.type && price > other.price;
}

std::string Overcoat::getType() const {
    return type;
}

double Overcoat::getPrice() const {
    return price;
}
