#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <string>
#include <iostream>

Intern::Intern() {
	this->pairs[0].m_name = "PresidentialPardonForm";
	this->pairs[0].member = &Intern::getPresidentialPardonForm;
	this->pairs[1].m_name = "RobotomyRequestForm";
	this->pairs[1].member = &Intern::getRobotomyRequestForm;
	this->pairs[2].m_name = "ShrubberyCreationForm";
	this->pairs[2].member = &Intern::getShrubberyCreationForm;
}

Intern::Intern(const Intern &copy) {
	(void)copy;
	this->pairs[0].m_name = "PresidentialPardonForm";
	this->pairs[0].member = &Intern::getPresidentialPardonForm;
	this->pairs[1].m_name = "RobotomyRequestForm";
	this->pairs[1].member = &Intern::getRobotomyRequestForm;
	this->pairs[2].m_name = "ShrubberyCreationForm";
	this->pairs[2].member = &Intern::getShrubberyCreationForm;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Form *Intern::getRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

Form *Intern::getShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

Form *Intern::getPresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}


Form *Intern::makeForm(const std::string &name, const std::string &target) {
	for (int i = 0; i < FORMS_CNT; ++i) {
		if ((this->pairs)[i].m_name == name) {
			std::cout << "\033[3;37mIntern create " << name
			          << "\033[0m" << std::endl;
			return (this->*pairs[i].member)(target);
		}
	}
	throw Intern::FormNotFoundException();
}

Intern::FormNotFoundException::FormNotFoundException() :
		std::out_of_range("\033[3;31mForm not found\033[0m") {}