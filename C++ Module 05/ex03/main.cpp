#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {

	Bureaucrat boss("Boss", 1);
	Bureaucrat worker("Worker", 71);

	Intern alex;

	Form *form1 = alex.makeForm("ShrubberyCreationForm", "office_garden");
	Form *form2 = alex.makeForm("RobotomyRequestForm", "coffee_machine");
	Form *form3 = alex.makeForm("PresidentialPardonForm", "boss_cat");

	worker.executeForm(*form1);
	worker.signForm(*form1);
	worker.executeForm(*form1);

	worker.signForm(*form2);
	worker.executeForm(*form2);
	boss.executeForm(*form2);
	boss.executeForm(*form2);

	worker.signForm(*form3);
	boss.signForm(*form3);
	boss.executeForm(*form3);

	boss.signForm(*form3);

	delete form1;
	delete form2;
	delete form3;
}

