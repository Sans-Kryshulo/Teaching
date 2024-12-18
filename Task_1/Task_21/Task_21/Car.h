// Car.h
#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    std::string name;
    int year;
    double engineVolume;
    double price;

public:
    Car(const std::string& name, int year, double engineVolume, double price);

    std::string GetName() const;
    int GetYear() const;
    double GetEngineVolume() const;
    double GetPrice() const;

    void PrintInfo() const;

    // Comparison operators for sorting
    bool operator<(const Car& other) const;
    bool operator>(const Car& other) const;
};

#endif // CAR_H
