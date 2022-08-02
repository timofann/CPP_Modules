#include "Contact.h"
#include "PhoneBook.h"
#include <iostream>

int main(void) {

	PhoneBook 	pb;
	std::string	command;

	std::cout << "\033[3;35mCurrently you are in an empty PhoneBook\033[0m"
			  << std::endl << std::endl;
	while(1) {

		std::cout << "\033[3;35mEnter one of the next commands: " << std::endl
				  << "'add' - add new contact to the PhoneBook;" << std::endl
				  << "'search' - search the contact through the PhoneBook;" << std::endl
				  << "'exit' - leave current session.\033[0m" << std::endl
				  << "\033[3m>> ";
		std::cin >> command;
		std::cout << "\033[0m";

		if (std::cin.eof())
			break ;

		if (command == "add")
			pb.add();
		else if (command == "search")
			pb.search();
		else if (command == "exit")
			break ;
		else
			std::cout << "\033[3;35mInvalid command\033[0m"
					  << std::endl << std::endl;
	}
	return (0);
}
