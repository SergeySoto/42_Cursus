#include "AMateria.hpp"

AMateria::AMateria() : _type("No Materia") {
}

AMateria::AMateria(std::string const& type) : _type(type) {
}

AMateria::AMateria(const AMateria& copy) : _type(copy._type) {
}

AMateria& AMateria::operator=(const AMateria& copy) {
	(void)copy;
	return *this;
}

AMateria::~AMateria() {
}

std::string const& AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}