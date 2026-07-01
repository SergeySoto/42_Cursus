#include "Animal.hpp"

Animal::Animal() : _type("Undefined") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal Type constructor called" << std::endl;
}

Animal::Animal(const Animal& copy) {
	std::cout << "Copy constructor called" << std::endl;
	_type = copy._type;
}

Animal& Animal::operator=(const Animal& copy) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal desctructor called" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << Animal::getType() << " makes a sound." << std::endl;
}