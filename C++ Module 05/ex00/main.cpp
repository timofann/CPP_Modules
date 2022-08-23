#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void) {

	try {
		Bureaucrat harry = Bureaucrat("Harry", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat helena = Bureaucrat("Helena", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat dolly("Dolly", 1);
	std::cout << dolly << std::endl;
	try {
		dolly.incrementGrade();
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat greg("Greg", 150);
	std::cout << greg << std::endl;
	try {
		greg.decrementGrade();
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
}

