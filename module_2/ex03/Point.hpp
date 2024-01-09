#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
    Point();
    Point(float const x, float const y);
    Point(const Point& source);
    ~Point();

    Point& operator=(Point const&);

    float getX(void) const;
    float getY(void) const;

private:
    Fixed const x;
    Fixed const y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
