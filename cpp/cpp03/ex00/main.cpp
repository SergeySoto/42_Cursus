#include "ClapTrap.hpp"

int main () {
	ClapTrap enemy1("Juan");
	ClapTrap enemy2;
	std::cout << std::endl;

	for (int i = 0; i < 6; ++i)
	{
		enemy1.attack("enemy2");
		if (enemy1.getEnergyP() > 0 && enemy1.getHitP() > 0)
			enemy2.takeDamage(2);
		std::cout << std::endl;
		enemy2.attack("Juan");
		if (enemy2.getEnergyP() > 0 && enemy2.getHitP() > 0)
			enemy1.takeDamage(3);
		std::cout << std::endl;
		enemy1.beRepaired(5);
		enemy1.attack("enemy2");
		if (enemy1.getEnergyP() > 0 && enemy1.getHitP() > 0)
			enemy2.takeDamage(5);
		std::cout << std::endl;
	}

	return 0;
}
