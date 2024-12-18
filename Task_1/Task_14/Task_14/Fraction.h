#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int denom = 1);

    int getNumerator() const;
    int getDenominator() const;

    Fraction& operator++();
    Fraction& operator--();

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
    friend std::istream& operator>>(std::istream& is, Fraction& frac);
};

#endif
