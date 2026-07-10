#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
	private:
		AForm* makeShrubbery(const std::string& nameForm) const;
		AForm* makeRobotomy(const std::string& nameForm) const;
		AForm* makePresident(const std::string& nameForm) const;
	public:
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);
		~Intern();
		AForm* makeForm(const std::string& nameForm, const std::string& target);
		class FormNotFound : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif