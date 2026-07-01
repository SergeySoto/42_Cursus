#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
			Fixed const x;
			Fixed const y;
	public:
			Point();
			Point(const Point& copy);
			Point(const float f1, const float f2);
			Point& operator=(const Point& copy);
			~Point();
			Fixed getX() const;
			Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif