#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {}

Fixed::Fixed(const int value) {
    this->fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value) {
    this->fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& fixed) {
    *this = fixed;  // will use the assignation operator
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& fixed) {
    this->fixedPointValue = fixed.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed& other) const {
    return fixedPointValue > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return fixedPointValue < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return !(fixedPointValue < other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const {
    return !(fixedPointValue > other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const {
    return fixedPointValue == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return !(fixedPointValue == other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.toFloat() == 0) {
        std::cout << "\e[31mError: Division by zero\e[0m" << std::endl;
        return Fixed();
    }
    return Fixed(toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed& Fixed::operator--() {
    fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return a > b ? a : b;
}

int Fixed::getRawBits() const {
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->fixedPointValue = raw;
}

float Fixed::toFloat() const {
    return (float)this->fixedPointValue / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return this->fixedPointValue >> fractionalBits;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed) {
    stream << fixed.toFloat();
    return stream;
}
