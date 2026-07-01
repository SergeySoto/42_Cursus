#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unnamed"),
						_hitPoints(10),
						_energyPoints(10),
						_attackDamage(0) {
	std::cout << GREEN << "ClapTrap's Default constructor called" << RESET << std::endl;
} 

ClapTrap::ClapTrap(std::string name) : _name(name),
										_hitPoints(10),
										_energyPoints(10),
										_attackDamage(0) {
	std::cout << GREEN << "ClapTrap's Name constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) : _name(copy._name),
											_hitPoints(copy._hitPoints),
											_energyPoints(copy._energyPoints),
											_attackDamage(copy._attackDamage) {
	std::cout << GREEN << "ClapTrap's Copy constructor called" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
	std::cout << "ClapTrap's Copy assignment operator called" << std::endl;
	if (this != &copy) {
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << RED << "ClapTrap's Destructor called" << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		--_energyPoints;
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << ", causing " << _attackDamage << " points of damage" << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0)
	{
		if (_hitPoints <= static_cast<int>(amount))
			_hitPoints = 0;
		else
			_hitPoints -= amount;
	}
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << PURPLE << _name << RESET << " is dead" << std::endl;
	else {
		std::cout << "ClapTrap " << PURPLE << _name << RESET << " received " << amount;
		std:: cout << " of damage." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		--_energyPoints;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repaired " << amount;
		std::cout << " of hit points." << std::endl; 
	}
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " has no energy left to be repaired!" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is dead and cannot be repaired!" << std::endl;
}

int ClapTrap::getEnergyP() const {
	return _energyPoints;
}

int ClapTrap::getHitP() const {
	return _hitPoints;
}