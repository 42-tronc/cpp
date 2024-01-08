#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float aToC = (c.getX() - point.getX()) * (a.getY() - point.getY()) -
                 (c.getY() - point.getY()) * (a.getX() - point.getX());
    float aToB = (a.getX() - point.getX()) * (b.getY() - point.getY()) -
                 (a.getY() - point.getY()) * (b.getX() - point.getX());
    float bToC = (b.getX() - point.getX()) * (c.getY() - point.getY()) -
                 (b.getY() - point.getY()) * (c.getX() - point.getX());
    if ((aToB > 0.0 && bToC > 0.0 && aToC > 0.0) ||
        (aToB < 0.0 && bToC < 0.0 && aToC < 0.0))
        return true;
    return false;
}
