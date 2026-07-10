#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		std::string const _name;
		bool _signed;
		const int _gradeSigned;
		const int _gradeExec;
	public:
		Form();
		Form(const std::string& name, int gradeSigned, int gradeExec);
		Form(const Form& copy);
		Form& operator=(const Form& copy);
		~Form();

		const std::string& getName() const;
		bool getSigned() const;
		int getGradeSigned() const;
		int getGradeExec() const;
		void beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif