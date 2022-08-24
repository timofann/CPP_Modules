#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#define FORMS_CNT 3

class Intern;

typedef struct s_pair {
	std::string m_name;
	Form        *(Intern::*member)(const std::string &);
}	t_pair;

class Intern {
private:
	t_pair  pairs[FORMS_CNT];
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();
	Intern  &operator=(const Intern &other);
	Form    *makeForm(const std::string &name, const std::string &target);
	Form    *getRobotomyRequestForm(const std::string &target);
	Form    *getShrubberyCreationForm(const std::string &target);
	Form    *getPresidentialPardonForm(const std::string &target);

	class FormNotFoundException : public std::out_of_range {
	public:
		FormNotFoundException();
	};
};

#endif
