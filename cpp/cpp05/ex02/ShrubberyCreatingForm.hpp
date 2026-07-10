#ifndef SHRUBBERYCREATINGFORM_HPP
# define SHRUBBERYCREATINGFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreatingForm : public AForm {
	private:
		const std::string _target;
	protected:
		virtual void executeAction() const;
	public:
		ShrubberyCreatingForm();
		ShrubberyCreatingForm(const std::string& target);
		ShrubberyCreatingForm(const ShrubberyCreatingForm& copy);
		ShrubberyCreatingForm& operator=(const ShrubberyCreatingForm& copy);
		~ShrubberyCreatingForm();

		class FileOpenException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
