#include "Zombie.hpp"

Zombie::Zombie() : _zombieName("") {
}

Zombie::~Zombie(void) {
	std::cout << this->_zombieName << " zombie has been destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
	_zombieName = name;
}

void Zombie::announce(void) {
	std::cout << this->_zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}