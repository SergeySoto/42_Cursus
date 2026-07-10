#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreatingForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentPardonForm.hpp"
#include <ctime>

int main() {
	std::srand(std::time(NULL));
	Bureaucrat person1 = Bureaucrat();
	Bureaucrat chaevist("Hugo Chavez", 1);
	ShrubberyCreatingForm form1 = ShrubberyCreatingForm("Budget");
	RobotomyRequestForm form2 = RobotomyRequestForm("Military man");
	PresidentPardonForm form3 = PresidentPardonForm("Maryah Korina");

	AForm* form_ptr = new PresidentPardonForm("gay");

	try {
		std::cout << "----- ShrubberyCreatinForm info -----" << std::endl;
		std::cout << std::endl;
		std::cout << form1 << std::endl;
		std::cout << std::endl;
		person1.executeForm(form1);
		chaevist.executeForm(form1);
		chaevist.signAForm(form1);
		chaevist.executeForm(form1);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << std::endl;
		std::cout << "----- RobotomyRequestForm info -----" << std::endl;
		std::cout << std::endl;
		std::cout << form2 << std::endl;
		person1.signAForm(form2);
		person1.executeForm(form2);
		chaevist.signAForm(form2);
		chaevist.executeForm(form2);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << std::endl;
		std::cout << "----- PresidentPardonForm info -----" << std::endl;
		std::cout << std::endl;
		std::cout << form3 << std::endl;
		person1.signAForm(form3);
		person1.executeForm(form3);
		chaevist.signAForm(form3);
		chaevist.executeForm(form3);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << std::endl;
		std::cout << "----- Dinamic form test -----" << std::endl;
		form_ptr->execute(chaevist);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	delete form_ptr;
	return 0;
}