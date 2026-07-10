#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("No name"), _grade(150) {
	std::cout << "Bureaucrat's constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("No name") {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat's int constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat's parameters constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << "Bureaucrat's copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
	if (this != &copy)
		this->_grade = copy._grade;
	std::cout << "Bureaucrat's assignment operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat's destructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade -= 1;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade += 1;
}

void Bureaucrat::signAForm(AForm& AForm) {
	try {
		AForm.beSigned(*this);
	}
		catch (const std::exception& e) {
			std::cout << this->getName() << " couldn't sign "
			<< AForm.getName() << " because " << e.what() << std::endl;
			return ;
		}
	std::cout << this->getName() << " signed " << AForm.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const& form) const {
	try {
		form.execute(*this);
	}
		catch (const std::exception& e) {
			std::cout << "Error trying to execute this form because " << e.what() << std::endl;
			return ;
		}
	std::cout << this->_name << " executed " << form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return RED "Grade too high, try lower grade." RESET;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return RED "Grade too low, try higher grade." RESET;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}
