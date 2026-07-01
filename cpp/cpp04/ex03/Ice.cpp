#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice& copy) : AMateria(copy) {
}

Ice& Ice::operator=(const Ice& copy) {
	AMateria::operator=(copy);
	return *this;
}

Ice::~Ice() {
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}