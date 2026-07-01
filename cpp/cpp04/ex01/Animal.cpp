#include "Animal.hpp"

Animal::Animal() : _type("Undefined") {
	std::cout << YELLOW << "Animal constructor called" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << YELLOW << "Animal Type constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal& copy) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	_type = copy._type;
}

Animal& Animal::operator=(const Animal& copy) {
	std::cout << YELLOW << "Assignment operator called" << RESET << std::endl;
	if (this != &copy)
		_type = copy._type;
	return *this;
}

Animal::~Animal() {
	std::cout << YELLOW << "Animal's desctructor called" << RESET << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << YELLOW << Animal::getType() << " makes a sound." << RESET << std::endl;
}