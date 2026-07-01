#include "Fixed.hpp"

Fixed::Fixed() : _fixP(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(int const num) {
	std::cout << "Int constructor called" << std::endl;
	_fixP = num << _numBit;
}

Fixed::Fixed(float const num) {
	std::cout << "Float constructor called" << std::endl;
	_fixP = roundf(num * (1 << _numBit));
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixP = other._fixP;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixP;
}

void Fixed::setRawBits(int const raw) {
	this->_fixP = raw;
}

int Fixed::toInt() const {
	return _fixP >> _numBit;
}

float Fixed::toFloat() const {
	return (float)_fixP / (1 << _numBit);
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
	out << f.toFloat();
	return out;
}