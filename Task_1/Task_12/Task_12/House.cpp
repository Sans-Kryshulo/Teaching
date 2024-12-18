#include "House.h"
#include <iostream>

House::House(std::string address) : address(address) {}

// Конструктор копирования
House::House(const House& other) : address(other.address), apartments(other.apartments) {}

// Деструктор
House::~House() {
    std::cout << "Дом  " << address << " уничтожен." << std::endl;
}

void House::addApartment(int number) {
    apartments.push_back(Apartment(number));
}

void House::addPersonToApartment(int apartmentNumber, std::string personName) {
    for (auto& apartment : apartments) {
        if (apartment.getNumber() == apartmentNumber) {
            apartment.addPerson(personName);
            return;
        }
    }
    std::cout << "Квартира  " << apartmentNumber << " не найдена!" << std::endl;
}

void House::print() {
    std::cout << "Адреса дома: " << address << std::endl;
    for (const auto& apartment : apartments) {
        apartment.print();
    }
}