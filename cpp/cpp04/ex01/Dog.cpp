#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << BLUE << "Dog's type constructor called" << RESET << std::endl;
	ObjBrain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << BLUE << "Dog's copy constructor called" << RESET << std::endl;
	ObjBrain = new Brain(*(copy.ObjBrain));
}

Dog& Dog::operator=(const Dog& copy) {
	if (this != &copy) {
		Animal::operator=(copy);
		*this->ObjBrain = *(copy.ObjBrain);
	}
	std::cout << BLUE << "Dog's assignment operator called" << RESET << std::endl;
	return *this;
}

Dog::~Dog () {
	std::cout << BLUE << "Dog's destructor called" << RESET << std::endl;
	delete ObjBrain;
}

void Dog::makeSound() const {
	std::cout << BLUE << Dog::getType() << " says: Guau!" << RESET << std::endl; 
}