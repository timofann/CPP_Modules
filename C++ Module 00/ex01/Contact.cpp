#include <string>
#include <iostream>
#include "Contact.h"
#include "table_cell.h"

Contact::Contact(void) {

	std::cout << "\033[3;37m"
			  << "--------------------- Contact default constructor called"
			  << "\033[0m" << std::endl << std::endl;
}

Contact::Contact(std::string _first_name,
				 std::string _last_name,
				 std::string _nickname,
				 std::string _phone_number,
				 std::string _darkest_secret) {

	std::cout << "\033[3;37m"
		      << "------ Contact constructor called for the next instance:"
		      << "\033[0m" << std::endl;

	std::cout << "\033[3;37m"
			  << "|first_name| last_name|  nickname|phone_num.|darkest_s.|"
			  << std::endl;

	this->first_name = _first_name;
	this->last_name = _last_name;
	this->nickname = _nickname;
	this->phone_number = _phone_number;
	this->darkest_secret = _darkest_secret;
	this->printInfo();
	std::cout << std::endl;
}

Contact::~Contact(void) {

	std::cout << "\033[3;37m"
		<< "------- Contact destructor called for the next instance:"
		<< "\033[0m" << std::endl;

	std::cout << "\033[3;37m"
			  << "|first_name| last_name|  nickname|phone_num.|darkest_s.|"
			  << "\033[0m" << std::endl;

	this->printInfo();
	std::cout << std::endl;
}

void Contact::printInfo(void) {

	std::string cell;

	std::cout << "\033[3;37m";
	std::cout << "|" << table_cell(this->first_name, &cell);
	std::cout << "|" << table_cell(this->last_name, &cell);
	std::cout << "|" << table_cell(this->nickname, &cell);
	std::cout << "|" << table_cell(this->phone_number, &cell);
	std::cout << "|" << table_cell(this->darkest_secret, &cell);
	std::cout << "|" << "\033[0m" << std::endl;
}
