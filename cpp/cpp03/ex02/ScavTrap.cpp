#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREEN << "ScavTrap's Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREEN << "ScavTrap's Name constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	std::cout << GREEN << "ScavTrap's Copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
	if (this != &copy) {
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	std::cout << GREEN << "ScavTrap's Copy assigment operator called" << RESET << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << RED << "ScavTrap's Destructor called" << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		--_energyPoints;
		std::cout << "ScavTrap " << YELLOW << _name << RESET << " attacks " << target;
		std::cout << ", causing " << _attackDamage << " points of damage" << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << "ScavTrap " << _name << " has no energy left to attack!" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << BLUE << _name << RESET << " is now in Gate keeper mode!" << std::endl;
}