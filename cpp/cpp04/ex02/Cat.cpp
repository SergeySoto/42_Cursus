#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	std::cout << PURPLE << "Cat's type constructor called" << RESET << std::endl;
	ObjBrain = new Brain();
}

Cat::Cat(const Cat& copy) : AAnimal(copy) {
	std::cout << PURPLE << "Cat's copy constructor called" << RESET << std::endl;
	ObjBrain = new Brain(*(copy.ObjBrain));
}

Cat& Cat::operator=(const Cat& copy) {
	if (this != &copy) {
		AAnimal::operator=(copy);
		*this->ObjBrain = *(copy.ObjBrain);
	}
	std::cout << PURPLE << "Cat's assignment operator called" << RESET << std::endl;
	return *this;
}

Cat::~Cat () {
	std::cout << PURPLE << "Cat's destructor called" << RESET << std::endl;
	delete ObjBrain;
}

void Cat::makeSound() const {
	std::cout << PURPLE << Cat::getType() << " says: Miau!" << RESET << std::endl; 
}