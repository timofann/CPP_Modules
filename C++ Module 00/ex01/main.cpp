/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:50:05 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/03 20:50:05 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include "PhoneBook.h"
#include <iostream>

int main(void) {

	PhoneBook 	myAwesomePhoneBook;
	std::string	command;

	std::cout << "\033[3;35mCurrently you are in an empty PhoneBook\033[0m"
			  << std::endl << std::endl;
	while(1) {

		std::cout << "\033[3;35mEnter one of the next commands: " << std::endl
				  << "'add' - add new contact to the PhoneBook;" << std::endl
				  << "'search' - search the contact through the PhoneBook;" << std::endl
				  << "'exit' - leave current session.\033[0m" << std::endl
				  << "\033[3m>> ";
		std::getline(std::cin, command);
		std::cout << "\033[0m";

		if (std::cin.eof())
			break ;
		if (command == "add" || command == "ADD")
			myAwesomePhoneBook.add();
		else if (command == "search" || command == "SEARCH")
			myAwesomePhoneBook.search();
		else if (command == "exit" || command == "EXIT")
			break ;
		else
			std::cout << "\033[3;35mInvalid command\033[0m"
					  << std::endl << std::endl;
	}
	return (0);
}
