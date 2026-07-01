#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure& copy) : AMateria(copy) {
}

Cure& Cure::operator=(const Cure& copy) {
	AMateria::operator=(copy);
	return *this;
}

Cure::~Cure() {
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}