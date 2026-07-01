#include "Point.hpp"

static Fixed crossProduct(Point const a, Point const b, Point const point) {
	return ((b.getX() - a.getX()) * (point.getY() - a.getY())) - 
			((b.getY() - a.getY()) * (point.getX() - a.getX()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {

	Fixed cross1 = crossProduct(a, b, point);
	Fixed cross2 = crossProduct(b, c, point);
	Fixed cross3 = crossProduct(c, a, point);

	Fixed zero(0);

	bool allPositive = (cross1 > zero) && (cross2 > zero) && (cross3 > zero);
	bool allNegative = (cross1 < zero) && (cross2 < zero) && (cross3 < zero);

	return (allPositive || allNegative);
}