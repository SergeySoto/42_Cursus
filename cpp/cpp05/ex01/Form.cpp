#include "Form.hpp"

Form::Form() : _name("Form without name"), _signed(false), _gradeSigned(100), _gradeExec(50) {
}

Form::Form(const std::string& name, int gradeSigned, int gradeExec)
:	_name(name),
	_signed(false),
	_gradeSigned(gradeSigned),
	_gradeExec(gradeExec) {
	if (_gradeSigned > 150)
		throw Form::GradeTooLowException();
	if (_gradeSigned < 1)
		throw Form::GradeTooHighException();
	if (_gradeExec > 150)
		throw Form::GradeTooLowException();
	if (_gradeExec < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& copy) : _name(copy._name),
							_signed(copy._signed), 
							_gradeSigned(copy._gradeSigned),
							_gradeExec(copy._gradeExec) {
}

Form& Form::operator=(const Form& copy) {
	if (this != &copy)
		this->_signed = copy._signed;
	return *this;
}

Form::~Form() {
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeSigned() const {
	return _gradeSigned;
}

int Form::getGradeExec() const {
	return _gradeExec;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_gradeSigned)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << "Form: " << obj.getName() << std::endl;
	os << "Signed: " << obj.getSigned() << std::endl;
	os << "Grade required to sign: " << obj.getGradeSigned() << std::endl;
	os << "Grade required  to execute: " << obj.getGradeExec() << std::endl;
	return os;
}

const char* Form::GradeTooHighException::what() const throw() {
	return RED "Grade too high.\n" RESET;
}

const char* Form::GradeTooLowException::what() const throw() {
	return RED "Grade too low.\n" RESET;
}