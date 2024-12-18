#include "Fraction.h"

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction& Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& frac) {
    is >> frac.numerator >> frac.denominator;
    return is;
}
