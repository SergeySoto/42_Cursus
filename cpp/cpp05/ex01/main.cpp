#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat person1 = Bureaucrat();
	Bureaucrat Miguel("Miguel", 2);
	Form form1 = Form("Office budget", 2, 1);
	Form form2 = Form();

	std::cout << "----- Form info -----" << std::endl;
	try {
		std::cout << form1 << std::endl;
		person1.signForm(form1);
		person1.signForm(form2);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << std::endl;
		std::cout << form2 << std::endl;
		Miguel.signForm(form2);
		Miguel.signForm(form1);
	} catch ( const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}