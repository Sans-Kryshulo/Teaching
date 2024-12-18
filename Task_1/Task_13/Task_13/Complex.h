#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex();
    Complex(double r, double i);

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
};

#endif
