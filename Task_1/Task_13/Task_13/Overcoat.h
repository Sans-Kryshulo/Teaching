#ifndef OVERCOAT_H
#define OVERCOAT_H

#include <string>

class Overcoat {
private:
    std::string type;
    double price;

public:
    Overcoat();
    Overcoat(const std::string& t, double p);

    bool operator==(const Overcoat& other) const;
    Overcoat& operator=(const Overcoat& other);
    bool operator>(const Overcoat& other) const;

    std::string getType() const;
    double getPrice() const;
};

#endif
