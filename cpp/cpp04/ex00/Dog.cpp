#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog's type constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << "Dog's copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	if (this != &copy)
		this->_type = copy._type;
	std::cout << "Dog's assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog () {
	std::cout << "Dog's destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << Dog::getType() << " says: Guau!" << std::endl; 
}