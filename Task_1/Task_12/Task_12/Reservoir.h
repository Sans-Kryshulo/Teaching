#pragma once
#ifndef RESERVOIR_H
#define RESERVOIR_H

#include <string>

class Reservoir {
private:
    std::string name;
    double width;
    double length;
    double maxDepth;

public:
    Reservoir();
    Reservoir(std::string name, double width, double length, double maxDepth);
    Reservoir(const Reservoir& other);
    ~Reservoir();

    std::string getName() const;
    double getWidth() const;
    double getLength() const;
    double getMaxDepth() const;

    void setName(std::string name);
    void setWidth(double width);
    void setLength(double length);
    void setMaxDepth(double maxDepth);

    double approximateVolume() const;
    double surfaceArea() const;
    bool sameType(const Reservoir& other) const;
    bool operator==(const Reservoir& other) const;
};

#endif // RESERVOIR_H