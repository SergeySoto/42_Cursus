#ifndef AForm_HPP
# define AForm_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
	private:
		std::string const _name;
		bool _signed;
		const int _gradeSigned;
		const int _gradeExec;
	protected:
		virtual void executeAction() const = 0;
	public:
		AForm();
		AForm(const std::string& name, int gradeSigned, int gradeExec);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& copy);
		virtual ~AForm();

		const std::string& getName() const;
		bool getSigned() const;
		int getGradeSigned() const;
		int getGradeExec() const;
		void beSigned(const Bureaucrat& b);
		void execute(const Bureaucrat& executor) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormNotSigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif