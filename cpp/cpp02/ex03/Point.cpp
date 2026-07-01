#include "Point.hpp"

Point::Point() : x(0), y(0){
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point& copy) : x(copy.x), y(copy.y) {
	//std::cout << "Copy constructor called" << std::endl;
}

Point::Point(const float f1,const float f2) : x(f1), y(f2) {
	//std::cout << "Float constructor called" << std::endl;
}

Point& Point::operator=(const Point& copy) {
	(void)copy;
	//std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Point::~Point() {
	//std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const {
	return this->x;
}

Fixed Point::getY() const {
	return this->y;
}