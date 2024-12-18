#include "Apartment.h"
#include <iostream>

Apartment::Apartment(int number) : number(number) {}

// Конструктор копирования
Apartment::Apartment(const Apartment& other) : number(other.number), residents(other.residents) {}

// Деструктор
Apartment::~Apartment() {
    std::cout << "Номер квартири " << number << " уничтожен." << std::endl;
}

void Apartment::addPerson(std::string personName) {
    residents.push_back(Person(personName));
}

int Apartment::getNumber() const {
    return number;
}

void Apartment::print() const {
    std::cout << "Номер квартири: " << number << std::endl;
    if (residents.empty()) {
        std::cout << "Нету людей в квартире." << std::endl;
    }
    else {
        for (const auto& resident : residents) {
            std::cout << " - " << resident.getName() << std::endl;
        }
    }
}