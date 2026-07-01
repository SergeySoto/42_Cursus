#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	private:
			std::string _name;
			int _hitPoints;
			int _energyPoints;
			int _attackDamage;
	public:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap& copy);
			ClapTrap& operator=(const ClapTrap& copy);
			~ClapTrap();
			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
			int getEnergyP() const;
			int getHitP() const;
};

#endif