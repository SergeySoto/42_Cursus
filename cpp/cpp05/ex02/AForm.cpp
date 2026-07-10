#include "AForm.hpp"

AForm::AForm() : _name("AForm without name"), _signed(false), _gradeSigned(100), _gradeExec(50) {
}

AForm::AForm(const std::string& name, int gradeSigned, int gradeExec)
:	_name(name),
	_signed(false),
	_gradeSigned(gradeSigned),
	_gradeExec(gradeExec) {
	if (_gradeSigned > 150)
		throw AForm::GradeTooLowException();
	if (_gradeSigned < 1)
		throw AForm::GradeTooHighException();
	if (_gradeExec > 150)
		throw AForm::GradeTooLowException();
	if (_gradeExec < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& copy) : _name(copy._name),
							_signed(copy._signed), 
							_gradeSigned(copy._gradeSigned),
							_gradeExec(copy._gradeExec) {
}

AForm& AForm::operator=(const AForm& copy) {
	if (this != &copy)
		this->_signed = copy._signed;
	return *this;
}

AForm::~AForm() {
}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeSigned() const {
	return _gradeSigned;
}

int AForm::getGradeExec() const {
	return _gradeExec;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_gradeSigned)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << "AForm: " << obj.getName() << std::endl;
	os << "Signed: " << obj.getSigned() << std::endl;
	os << "Grade required to sign: " << obj.getGradeSigned() << std::endl;
	os << "Grade required to execute: " << obj.getGradeExec() << std::endl;
	return os;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return RED "Grade too high." RESET;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return RED "Grade too low." RESET;
}

const char* AForm::FormNotSigned::what() const throw() {
	return RED "Form Not signed." RESET;
}

void AForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->_gradeExec)
		throw AForm::GradeTooLowException();
	if (getSigned() == false)
		throw AForm::FormNotSigned();
	this->executeAction(); 
}