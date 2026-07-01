#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat's type constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat's copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
	if (this != &copy)
		this->_type = copy._type;
	std::cout << "Cat's assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat () {
	std::cout << "Cat's destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << Cat::getType() << " says: Miau!" << std::endl; 
}