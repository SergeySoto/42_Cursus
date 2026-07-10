#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreatingForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>

int main() {
	std::srand(std::time(NULL));
	Bureaucrat person1 = Bureaucrat();
	Bureaucrat chaevist("Hugo Chavez", 1);
	Intern intern = Intern();
	AForm* form = NULL;

	try {
		std::cout << "----- ShrubberyCreatinForm info -----" << std::endl;
		std::cout << std::endl;
		form = intern.makeForm("shrubbery creation", "Budget");
		std::cout << *form << std::endl;
		std::cout << std::endl;
		person1.executeForm(*form);
		chaevist.executeForm(*form);
		chaevist.signAForm(*form);
		chaevist.executeForm(*form);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	if (form != NULL){
		delete form;
		form = NULL;
	}
	try {
		std::cout << std::endl;
		std::cout << "----- RobotomyRequestForm info -----" << std::endl;
		std::cout << std::endl;
		form = intern.makeForm("robotomy request", "Military man");
		std::cout << std::endl;
		std::cout << *form << std::endl;
		person1.signAForm(*form);
		person1.executeForm(*form);
		chaevist.signAForm(*form);
		chaevist.executeForm(*form);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	if (form != NULL) {
		delete form;
		form = NULL;
	}
	try {
		std::cout << std::endl;
		std::cout << "----- PresidentPardonForm info -----" << std::endl;
		std::cout << std::endl;
		form = intern.makeForm("presidential", "Maryah Korina");
		std::cout << std::endl;
		std::cout << *form << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	if (form != NULL) {
		delete form;
		form = NULL;
	}
	try {
		std::cout << std::endl;
		std::cout << "----- PresidentPardonForm info -----" << std::endl;
		std::cout << std::endl;
		form = intern.makeForm("presidential pardon", "Maryah Korina");
		std::cout << std::endl;
		std::cout << *form << std::endl;
		person1.signAForm(*form);
		person1.executeForm(*form);
		chaevist.signAForm(*form);
		chaevist.executeForm(*form);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	if (form != NULL) {
		delete form;
		form = NULL;
	}

	return 0;
}