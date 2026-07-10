#include "Bureaucrat.hpp"

int main() {

	Bureaucrat person1 = Bureaucrat();
	Bureaucrat person2("Miguel", 2);
	Bureaucrat person3;

	person3 = person2;
	std::cout << person2 << std::endl;
	std::cout << person3 << std::endl;
	std::cout << "----- Increment or decrement tests -----" << std::endl;
	try {
		person3.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		person1.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		person2.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		person2.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << person3 << std::endl;
	std::cout << "----- Class constructor fails tests -----" << std::endl;
	try {
		Bureaucrat cat1("Gardfield", 999);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat god1("Scooby Doo", 422);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}