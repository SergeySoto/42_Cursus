#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat's constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	std::cout << "WrongCat's copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	if (this != &copy)
		_type = copy._type;
	std::cout << "WrongCat's assignment operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std:: cout << "WrongCat's destrcutor called" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << getType() << " does not how to Miau! shame!!" << std::endl;
}