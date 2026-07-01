#include "ScavTrap.hpp"

int main () {
	ScavTrap enemy1("Juan");
	ScavTrap enemy2;
	std::cout << std::endl;

	for (int i = 0; i < 6; ++i)
	{
		enemy1.attack("enemy2");
		if (enemy1.getEnergyP() > 0 && enemy1.getHitP() > 0)
			enemy2.takeDamage(12);
		std::cout << std::endl;
		enemy2.attack("Juan");
		if (enemy2.getEnergyP() > 0 && enemy2.getHitP() > 0)
			enemy1.takeDamage(18);
		std::cout << std::endl;
		enemy1.guardGate();
		enemy1.attack("enemy2");
		if (enemy1.getEnergyP() > 0 && enemy1.getHitP() > 0)
			enemy2.takeDamage(15);
		std::cout << std::endl;
	}
	return 0;
}
