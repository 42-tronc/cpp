#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "\e[32mDefault constructor called\e[0m" << std::endl;
}

/**
 * @brief Constructs a Fixed object with an integer value.
 *
 * This constructor takes an integer value and initializes the Fixed object.
 * Shifting a binary number left by n bits is equivalent to multiplying it by
 * 2^n. So shifting a binary number left by 8 bits is equivalent to multiplying
 * it by 2^8, which is 256.
 *
 * @param value The integer value to be stored in the Fixed object.
 */
Fixed::Fixed(const int value) {
    std::cout << "\e[32mInt constructor called\e[0m" << std::endl;
    this->fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "\e[32mFloat constructor called\e[0m" << std::endl;
    this->fixedPointValue = roundf(value * (1 << fractionalBits));
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
    this->fixedPointValue = raw;
}

/**
 * @brief Converts the fixed-point value to a floating-point value.
 *
 * Shifting the fixed-point value right by the number of fractional bits
 * will give us the integer part of the number. Effectively, this is
 * equivalent to dividing the float cast of the fixed-point value by 256.
 *
 * @return The floating-point representation of the fixed-point value.
 */
float Fixed::toFloat() const {
    return (float)this->fixedPointValue / (1 << fractionalBits);
}

/**
 * @brief Converts the Fixed object to an integer value.
 *
 * Shifting the fixed-point value right by the number of fractional bits
 * will give us the integer part of the number. Effectively, this is
 * equivalent to dividing the fixed-point value by 256.
 *
 * @return The integer value of the Fixed object.
 */
int Fixed::toInt() const {
    return this->fixedPointValue >> fractionalBits;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed) {
    stream << fixed.toFloat();
    return stream;
}
