#include "Intern.hpp"
#include "ShrubberyCreatingForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentPardonForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& copy) {
	(void)copy;
}

Intern& Intern::operator=(const Intern& copy) {
	(void)copy;
	return *this;
}

Intern::~Intern() {
}

AForm* Intern::makeForm(const std::string& nameForm, const std::string& target) {
	std::string strForms [3];
	AForm* result;
	strForms[0] = "shrubbery creation";
	strForms[1] = "robotomy request";
	strForms[2] = "presidential pardon";
	AForm* (Intern::*funcs[3]) (const std::string& target) const;
	funcs[0] = &Intern::makeShrubbery;
	funcs[1] = &Intern::makeRobotomy;
	funcs[2] = &Intern::makePresident;
	for (int i = 0; i < 3; ++i) {
		if (strForms[i] == nameForm) {
			std::cout << "Intern creates " << nameForm << std::endl;
			result = (this->*funcs[i])(target);
			return result;
		}
	}
	throw Intern::FormNotFound();
}

AForm* Intern::makeShrubbery(const std::string& target) const {
	return new ShrubberyCreatingForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresident(const std::string& target) const {
	return new PresidentPardonForm(target);
}

const char* Intern::FormNotFound::what() const throw() {
	return RED "Form not found." RESET; 
}