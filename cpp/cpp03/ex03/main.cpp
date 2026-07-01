#include "DiamondTrap.hpp"

int main () {
	DiamondTrap enemy1;
	DiamondTrap enemy2("Quimera");
	DiamondTrap enemy3;
	enemy3 = enemy2;

	std::cout << "****************** enemy1 ***************" << std::endl;
	enemy1.whoAmI();
	std::cout << "HP: " << enemy1.getHitP() << " should be 100" << std::endl;
	std::cout << "EP: " << enemy1.getEnergyP() << " should be 50" << std::endl;
	std::cout << "AD: " << enemy1.getAttackD() << " should be 30" << std::endl;
	std::cout << "****************** enemy2 ***************" << std::endl;
	enemy2.whoAmI();
	std::cout << "HP: " << enemy2.getHitP() << " should be 100" << std::endl;
	std::cout << "EP: " << enemy2.getEnergyP() << " should be 50" << std::endl;
	std::cout << "AD: " << enemy2.getAttackD() << " should be 30" << std::endl;
	std::cout << "****************** enemy3 ***************" << std::endl;
	enemy3.whoAmI();
	std::cout << "HP: " << enemy3.getHitP() << " should be 100" << std::endl;
	std::cout << "EP: " << enemy3.getEnergyP() << " should be 50" << std::endl;
	std::cout << "AD: " << enemy3.getAttackD() << " should be 30" << std::endl;
	std::cout << "****************** enemy1 ***************" << std::endl;
	enemy1.attack("Quimera");
	std::cout << "****************** enemy2 ***************" << std::endl;
	enemy2.takeDamage(10);
	enemy2.beRepaired(5);
	enemy2.guardGate();
	std::cout << "****************** enemy3 ***************" << std::endl;
	enemy3.highFivesGuys();
	return 0;
}
