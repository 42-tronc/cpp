#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(const Fixed &fixed);
    ~Fixed();

    Fixed &operator=(const Fixed &fixed);

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int fixedPointValue;
    // Fixed-point values are essentially integers that are scaled by a factor
    // of 2^N. For example, if N is 8, then the number 42.42 would be
    // represented as 42.42 * 2^8 = 42.42 * 256 = 10854.
    static const int fractionalBits = 8;
    // Fractional bits are the number of bits used to represent the fractional
    // part of a fixed-point number.
};

#endif
