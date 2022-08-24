#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>

class PresidentialPardonForm : public Form {

private:
	std::string             target_;
public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();
	PresidentialPardonForm  &operator=(const PresidentialPardonForm &other);
	void                    execute(Bureaucrat const &executor) const;
};

#endif
