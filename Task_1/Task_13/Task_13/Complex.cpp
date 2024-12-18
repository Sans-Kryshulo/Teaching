#include "Complex.h"

Complex::Complex() : real(0.0), imaginary(0.0) {}

Complex::Complex(double r, double i) : real(r), imaginary(i) {}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imaginary - other.imaginary);
}

Complex Complex::operator*(const Complex& other) const {
    double newReal = real * other.real - imaginary * other.imaginary;
    double newImaginary = real * other.imaginary + imaginary * other.real;
    return Complex(newReal, newImaginary);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    double newReal = (real * other.real + imaginary * other.imaginary) / denominator;
    double newImaginary = (imaginary * other.real - real * other.imaginary) / denominator;
    return Complex(newReal, newImaginary);
}

std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << complex.real << " + " << complex.imaginary << "i";
    return os;
}
