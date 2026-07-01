#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i)
		this->_memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	for (int i = 0; i < 4; ++i) {
		if (copy._memory[i] != NULL) {
			this->_memory[i] = copy._memory[i]->clone();
		}
		else
			this->_memory[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {
	if (this != &copy) {
		for (int i = 0; i < 4; ++i) {
			if (this->_memory[i] != NULL)
				delete this->_memory[i];
			if (copy._memory[i] != NULL)
				this->_memory[i] = copy._memory[i]->clone();
			else
				this->_memory[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		if (_memory[i] != NULL)
			delete _memory[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; ++i) {
		if (this->_memory[i] == NULL) {
			this->_memory[i] = m;
			break;
		}
	}
	//delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; ++i)
		if (_memory[i] != NULL && (_memory[i]->getType() == type))
			return _memory[i]->clone();
	return NULL;
}