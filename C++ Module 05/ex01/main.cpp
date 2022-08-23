#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void) {

	try {
		Form hotel("book_hotel", 160, 30);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form restaurant("book_restaurant", 1, 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Form clean("clean_workspace", 50, 120);
	std::cout << clean << std::endl;
	Bureaucrat bob("Bob", 51);
	std::cout << bob << std::endl;
	bob.signForm(clean);
	bob.incrementGrade();
	bob.signForm(clean);
	bob.signForm(clean);
}

