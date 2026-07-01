#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Undefined") {
	std::cout << YELLOW << "AAnimal constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << YELLOW << "AAnimal Type constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) : _type(copy._type) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& copy) {
	std::cout << YELLOW << "Assignment operator called" << RESET << std::endl;
	if (this != &copy)
		_type = copy._type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << YELLOW << "AAnimal's desctructor called" << RESET << std::endl;
}

std::string AAnimal::getType() const {
	return _type;
}
