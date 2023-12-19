#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& fixed);
    ~Fixed();

    Fixed& operator=(const Fixed& fixed);

    // bool operator==(const Length& other) const;
    // bool operator==(int other) const;
    // bool operator!=(int other) const;
    // bool operator<(const Length& other) const;
    // bool operator<=(const Length& other) const;
    // bool operator>(const Length& other) const;
    // bool operator>=(const Length& other) const;
    // Length operator+(const Length& other) const;
    // Length operator+(const int other) const;
    // Length& operator+=(const Length& other);
    // Length& operator=(const Length& other);
    // Length& operator++();
    // Length operator++(int);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

private:
    int fixedPointValue;
    static const int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);
// std::istream& operator>>(std::istream& stream, Length& length);

#endif
