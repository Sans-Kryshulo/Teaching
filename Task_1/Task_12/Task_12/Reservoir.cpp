#include "reservoir.h"

Reservoir::Reservoir() : width(0), length(0), maxDepth(0) {}

Reservoir::Reservoir(std::string name, double width, double length, double maxDepth)
    : name(name), width(width), length(length), maxDepth(maxDepth) {}

Reservoir::Reservoir(const Reservoir& other)
    : name(other.name), width(other.width), length(other.length), maxDepth(other.maxDepth) {}

Reservoir::~Reservoir() {}

std::string Reservoir::getName() const {
    return name;
}

double Reservoir::getWidth() const {
    return width;
}

double Reservoir::getLength() const {
    return length;
}

double Reservoir::getMaxDepth() const {
    return maxDepth;
}

void Reservoir::setName(std::string name) {
    this->name = name;
}

void Reservoir::setWidth(double width) {
    this->width = width;
}

void Reservoir::setLength(double length) {
    this->length = length;
}

void Reservoir::setMaxDepth(double maxDepth) {
    this->maxDepth = maxDepth;
}

double Reservoir::approximateVolume() const {
    return width * length * maxDepth;
}

double Reservoir::surfaceArea() const {
    return width * length;
}

bool Reservoir::sameType(const Reservoir& other) const {
    return (name == other.name);
}

bool Reservoir::operator==(const Reservoir& other) const {
    return surfaceArea() == other.surfaceArea();
}