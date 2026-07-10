#ifndef PRESIDENTPARDONFORM_HPP
# define PRESIDENTPARDONFORM_HPP

#include "AForm.hpp"

class PresidentPardonForm : public AForm {
	private:
		const std::string _target;
	protected:
		virtual void executeAction() const;
	public:
		PresidentPardonForm();
		PresidentPardonForm(const std::string& target);
		PresidentPardonForm(const PresidentPardonForm& copy);
		PresidentPardonForm& operator=(const PresidentPardonForm& copy);
		~PresidentPardonForm();
};

#endif