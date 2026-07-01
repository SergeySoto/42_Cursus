#include "Brain.hpp"

Brain::Brain() {
	std::cout << GREEN << "Brain's constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& copy) {
	std::cout << GREEN << "Brain's copy constructor called" << RESET << std::endl;
	for (int i = 0; i <= 99; ++i) {
		_ideas[i] = copy._ideas[i];
	}
}

Brain& Brain::operator=(const Brain& copy) {
	std::cout << GREEN << "Brain's assignment operator called" << RESET << std::endl;
	if (this != &copy) {
		for (int i = 0; i <= 99; ++i) {
			_ideas[i] = copy._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << GREEN << "Brain's destructor called" << RESET << std::endl;

}