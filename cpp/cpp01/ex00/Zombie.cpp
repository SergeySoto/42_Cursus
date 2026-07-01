#include "Zombie.hpp"

void Zombie::announce(void) {
	std::cout << this->_zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : _zombieName(name)  {
}

Zombie::~Zombie(void) {
	std::cout << this->_zombieName << " zombie has been destroyed" << std::endl;
}

