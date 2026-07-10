#include "PresidentPardonForm.hpp"

PresidentPardonForm::PresidentPardonForm() : AForm("PresidentPardonForm", 25, 5), _target("Default target") {
}

PresidentPardonForm::PresidentPardonForm(const std::string& target) : AForm("PresidentPardonForm", 25, 5), _target(target) {
}

PresidentPardonForm::PresidentPardonForm(const PresidentPardonForm& copy) : AForm(copy), _target(copy._target) {
}

PresidentPardonForm& PresidentPardonForm::operator=(const PresidentPardonForm& copy) {
	AForm::operator=(copy);
	return *this;
}

PresidentPardonForm::~PresidentPardonForm() {
}

void PresidentPardonForm::executeAction() const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}