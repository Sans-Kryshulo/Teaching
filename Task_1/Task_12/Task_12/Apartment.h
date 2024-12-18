#ifndef APARTMENT_H
#define APARTMENT_H

#include "Person.h"
#include <vector>

class Apartment {
private:
    int number;
    std::vector<Person> residents;

public:
    Apartment(int number);
    Apartment(const Apartment& other); // Конструктор копирования
    ~Apartment(); // Деструктор
    void addPerson(std::string personName);
    int getNumber() const;
    void print() const;
};

#endif // APARTMENT_H