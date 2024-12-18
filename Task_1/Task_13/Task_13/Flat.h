#ifndef FLAT_H
#define FLAT_H

#include <string>

class Flat {
private:
    std::string address;
    double area;
    double price;

public:
    Flat();
    Flat(const std::string& addr, double a, double p);

    bool operator==(const Flat& other) const;
    Flat& operator=(const Flat& other);
    bool operator>(const Flat& other) const;

    std::string getAddress() const;
    double getArea() const;
    double getPrice() const;
};

#endif
