#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main(void) {

	Bureaucrat boss("Boss", 1);
	Bureaucrat worker("Worker", 71);

	ShrubberyCreationForm   office("office_garden");
	RobotomyRequestForm     coffee("coffee_machine");
	PresidentialPardonForm  cat("boss_cat");

	worker.executeForm(office);
	worker.signForm(office);
	worker.executeForm(office);

	worker.signForm(coffee);
	worker.executeForm(coffee);
	boss.executeForm(coffee);
	boss.executeForm(coffee);

	worker.signForm(cat);
	boss.signForm(cat);
	boss.executeForm(cat);

	boss.signForm(cat);
}

