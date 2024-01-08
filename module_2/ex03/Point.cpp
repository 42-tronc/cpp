#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const x, float const y) : x(x), y(y) {}

Point::Point(Point const& src) {
    *this = src;
}

Point::~Point() {}

Point& Point::operator=(const Point&) {
    return *this;
}

Fixed const& Point::getX() const {
    return x;
}

Fixed const& Point::getY() const {
    return y;
}
