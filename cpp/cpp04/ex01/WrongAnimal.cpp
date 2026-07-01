#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Undefined") {
	std::cout << "WrongAnimal's constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	_type = copy._type;
	std::cout << "Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
	if (this != &copy)
		_type = copy._type;
	std::cout << "WrongAnimal's assignment operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal's destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const {
	std::cout << getType() << " does not what sound to make" << std::endl;
}
