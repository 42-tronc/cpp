#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
    Point();
    Point(float const x, float const y);
    Point(Point const& src);
    ~Point();

    Point& operator=(Point const&);

    Fixed const& getX() const;
    Fixed const& getY() const;

private:
    Fixed const x;
    Fixed const y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

// class Point {
// public:
//     Point& operator=(Point const&);
//     ~Point(void);

//     float getX(void) const;
//     float getY(void) const;

// private:
//     Fixed const _x;
//     Fixed const _y;
// };

// bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
