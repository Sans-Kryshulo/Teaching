#include "House.h"
#include <iostream>

House::House(std::string address) : address(address) {}

// ����������� �����������
House::House(const House& other) : address(other.address), apartments(other.apartments) {}

// ����������
House::~House() {
    std::cout << "���  " << address << " ���������." << std::endl;
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
    std::cout << "��������  " << apartmentNumber << " �� �������!" << std::endl;
}

void House::print() {
    std::cout << "������ ����: " << address << std::endl;
    for (const auto& apartment : apartments) {
        apartment.print();
    }
}