#include "ShrubberyCreatingForm.hpp"

ShrubberyCreatingForm::ShrubberyCreatingForm() : AForm("ShrubberyCreatinForm", 145, 137), _target("Default target") {
}

ShrubberyCreatingForm::ShrubberyCreatingForm(const std::string& target) : AForm("ShrubberyCreatinForm", 145, 137), _target(target) {
}

ShrubberyCreatingForm::ShrubberyCreatingForm(const ShrubberyCreatingForm& copy) : AForm(copy), _target(copy._target) {
}

ShrubberyCreatingForm& ShrubberyCreatingForm::operator=(const ShrubberyCreatingForm& copy) {
	AForm::operator=(copy);
	return *this;
}

ShrubberyCreatingForm::~ShrubberyCreatingForm() {
}

void ShrubberyCreatingForm::executeAction() const {
	std::ofstream n_file((this->_target + "_shrubbery").c_str());
	if (!n_file.is_open())
		throw ShrubberyCreatingForm::FileOpenException();
	n_file << "       _-_" << std::endl;
	n_file << "    /~~   ~~\\" << std::endl;
	n_file << "  /~~       ~~\\" << std::endl;
	n_file << " {             }" << std::endl;
	n_file << "  \\ _-     -_ /" << std::endl;
	n_file << "   ~  \\\\ //  ~" << std::endl;
	n_file << "_- -   | | _- _" << std::endl;
	n_file << "  _ -  | |   -_" << std::endl;
	n_file << "       / \\" << std::endl;
}

const char* ShrubberyCreatingForm::FileOpenException::what() const throw() {
	return RED "Error, problems to create or openin a file." RESET;
}