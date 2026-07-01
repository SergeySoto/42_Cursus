#include "Weapon.hpp"

Weapon::Weapon(std:: string type) : _type(type)
{

}

Weapon::~Weapon()
{

}

const std::string& Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std:: string n_weapon)
{
	this->_type = n_weapon;
}
