#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default target") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), _target(copy._target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	AForm::operator=(copy);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::executeAction() const {
	std::cout << "*Drilling noises* (Bzzzzzzzzzz!!!!!!)" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized succesfully 50% of the time." << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}