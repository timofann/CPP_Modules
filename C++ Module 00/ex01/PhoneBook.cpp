#include <string>
#include <iostream>
#include "PhoneBook.h"
#include "Contact.h"
#include "table_cell.h"
#include <stdlib.h>

size_t	PhoneBook::id_counter = 0;

PhoneBook::PhoneBook(void) {

	std::cout << "\033[3;37m"
			  << "---- PhoneBook constructor called for the next instance:"
			  << "\033[0m" << std::endl;

	this->records_cnt = 0;
	this->id = PhoneBook::id_counter;
	PhoneBook::id_counter++;
	this->printInfo();
	std::cout << std::endl;
}

PhoneBook::~PhoneBook(void) {

	std::cout << "\033[3;37m"
			  << "----- PhoneBook destructor called for the next instance:"
			  << "\033[0m" << std::endl;
	this->printInfo();
	std::cout << std::endl;
}

void	PhoneBook::printInfo(void) {

	if (this->records_cnt > 0) {
		std::cout << "\033[3;37m"
				  << "|first_name| last_name|  nickname|phone_num.|darkest_s.|"
				  << std::endl;
	}
	for (size_t i = 0; i < this->records_cnt; i++) {
		this->records[i].printInfo();
	}
	std::cout << "\033[3;37m"
			  << "PhoneBookId: " << this->id
			  << "\033[0m" << std::endl;
}

void	PhoneBook::add(void) {

	Contact 	record;

//	std::cin.ignore();
	std::cout << "\033[3;36mfirst_name: \033[3;38m";
	std::getline(std::cin, record.first_name);
	std::cout << "\033[3;36mlast_name:  \033[3;38m";
	std::getline(std::cin, record.last_name);
	std::cout << "\033[3;36mnickname:  \033[3;38m";
	std::getline(std::cin, record.nickname);
	std::cout << "\033[3;36mphone_number:  \033[3;38m";
	std::getline(std::cin, record.phone_number);
	std::cout << "\033[3;36mdarkest_secret:  \033[3;38m";
	std::getline(std::cin, record.darkest_secret);
	std::cout << "\033[0m";

	if (this->records_cnt < 8) {
		this->records[records_cnt] = record;
		this->records_cnt++;
	}
	else {
		for (size_t i = 0; i < 7; i++)
			this->records[i] = this->records[i + 1];
		this->records[7] = record;
	}

	std::cout << "\033[3;37m"
			  << "----- PhoneBook add method called for the next instance:"
			  << "\033[0m" << std::endl;
	this->printInfo();
	std::cout << std::endl;
}

void	PhoneBook::search(void) {

	std::string	cell;
	std::string	index_str;
	long		index_long;

	std::cout << "\033[3;37m"
			  << "-- PhoneBook search method called for the next instance:"
			  << "\033[0m" << std::endl;
	this->printInfo();
	std::cout << std::endl;

	if (this->records_cnt > 0) {

		std::cout << "\033[3m"
				  << "|     index|first_name| last_name|  nickname|"
				  << std::endl;

		for (size_t i = 0; i < this->records_cnt; i++) {

			std::cout << "|" << table_cell(std::to_string(i), &cell);
			std::cout << "|" << table_cell(this->records[i].first_name, &cell);
			std::cout << "|" << table_cell(this->records[i].last_name, &cell);
			std::cout << "|" << table_cell(this->records[i].nickname, &cell);
			std::cout << "|" << std::endl;
		}

		std::cout << std::endl << "\033[3;36mEnter the index of the interesting contact: ";
		std::cin >> index_str;
		try {

			index_long = std::stol(index_str);
			if (index_long < 0 || (size_t)index_long > this->records_cnt - 1) {

				std::cout << "Index is out of range. PhoneBook supports now 0 - "
				          << this->records_cnt - 1
						  << " contacts\033[0m"
						  << std::endl;
			}
			else {

				std::cout << std::endl;
				std::cout << "first_name: "
						  << this->records[index_long].first_name << std::endl;
				std::cout << "last_name: "
						  << this->records[index_long].last_name << std::endl;
				std::cout << "nickname: "
						  << this->records[index_long].nickname << std::endl;
				std::cout << "phone_number: "
						  << this->records[index_long].phone_number << std::endl;
				std::cout << "darkest_secret: "
						  << this->records[index_long].darkest_secret << std::endl;
				std::cout << "\033[0m";
			}
		}
		catch (std::invalid_argument err) {

			std::cout << "Index should has type integer\033[0m" << std::endl;
		}
		catch (std::out_of_range err) {

			std::cout << "Overflow_error is catched\033[0m" << std::endl;
		}
	}
	else {

		std::cout << "\033[3;36mThere is no contacts in the PhoneBook\033[0m"
				  << std::endl;
	}
	std::cout << std::endl;
}
