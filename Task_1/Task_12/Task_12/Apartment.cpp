#include "Apartment.h"
#include <iostream>

Apartment::Apartment(int number) : number(number) {}

// ����������� �����������
Apartment::Apartment(const Apartment& other) : number(other.number), residents(other.residents) {}

// ����������
Apartment::~Apartment() {
    std::cout << "����� �������� " << number << " ���������." << std::endl;
}

void Apartment::addPerson(std::string personName) {
    residents.push_back(Person(personName));
}

int Apartment::getNumber() const {
    return number;
}

void Apartment::print() const {
    std::cout << "����� ��������: " << number << std::endl;
    if (residents.empty()) {
        std::cout << "���� ����� � ��������." << std::endl;
    }
    else {
        for (const auto& resident : residents) {
            std::cout << " - " << resident.getName() << std::endl;
        }
    }
}