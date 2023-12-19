#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "\e[32mDefault constructor called\e[0m" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "\e[33mCopy constructor called\e[0m" << std::endl;
    *this = fixed;  // will use the assignation operator
}

Fixed::~Fixed() {
    std::cout << "\e[31mDestructor called\e[0m" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
    std::cout << "\e[33mAssignation operator called\e[0m" << std::endl;
    this->fixedPointValue = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    // std::cout << "\e[34msetting raw value to\e[0m " << raw << std::endl;
    this->fixedPointValue = raw;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed) {
    stream << fixed.toFloat();
    return stream;
}
