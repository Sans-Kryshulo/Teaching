#ifndef HOUSE_H
#define HOUSE_H

#include "Apartment.h"
#include <vector>

class House {
private:
    std::string address;
    std::vector<Apartment> apartments;

public:
    House(std::string address);
    House(const House& other); // Конструктор копирования
    ~House(); // Деструктор
    void addApartment(int number);
    void addPersonToApartment(int apartmentNumber, std::string personName);
    void print();
};

#endif // HOUSE_H