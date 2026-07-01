#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie *nzombie = new Zombie(name);
	return nzombie;
}
