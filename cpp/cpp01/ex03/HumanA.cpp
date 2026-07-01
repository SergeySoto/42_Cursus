#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _type(weapon)
{

}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _type.getType() << std::endl;
}