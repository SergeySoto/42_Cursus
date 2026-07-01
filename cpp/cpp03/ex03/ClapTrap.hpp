#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[93m"
#define BLUE	"\033[34m"
#define PURPLE	"\033[35m"

class ClapTrap {
	protected:
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
			int getAttackD() const;
};

#endif