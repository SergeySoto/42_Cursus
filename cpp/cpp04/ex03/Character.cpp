#include "Character.hpp"

Character::Character() : _name("Unnamed") {
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& copy) : _name(copy._name){
	for (int i = 0; i < 4; ++i) {
		if (copy._inventory[i] != NULL)
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& copy) {
	if (this != &copy) {
		this->_name = copy._name;
		for (int i = 0; i < 4; ++i) {
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			if (copy._inventory[i] != NULL) {
				this->_inventory[i] = copy._inventory[i]->clone();
			}
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
}

const std::string& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (m) {
		for (int i = 0; i < 4; ++i) {
			if (this->_inventory[i] == NULL) {
				this->_inventory[i] = m;
				break;
			}
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3)
		this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if ((idx >= 0 && idx <= 3) && this->_inventory[idx] != NULL) {
		this->_inventory[idx]->use(target);
		return ;
	}
	std::cout << "Nothing happened" << std::endl;
}
