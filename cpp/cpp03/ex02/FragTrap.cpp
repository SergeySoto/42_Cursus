#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GREEN << "FragTrap's Default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GREEN << "FragTrap's Name constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	std::cout << GREEN << "FragTrap's Copy constructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
	if (this != &copy) {
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	std::cout << GREEN << "FragTrap's Copy assigment operator called" << RESET << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << RED << "FragTrap's Destructor called" << RESET << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << BLUE << _name << " raised its hand to receive a high five" << RESET << std::endl; 
}