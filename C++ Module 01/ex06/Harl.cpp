#include "Harl.h"
#include <iostream>

Harl::Harl(void) {
	this->pairs[0].m_name = "DEBUG";
	this->pairs[0].member = &Harl::debug;
	this->pairs[1].m_name = "INFO";
	this->pairs[1].member = &Harl::info;
	this->pairs[2].m_name = "WARNING";
	this->pairs[2].member = &Harl::warning;
	this->pairs[3].m_name = "ERROR";
	this->pairs[3].member = &Harl::error;
}

Harl::~Harl(void) {}

void	Harl::complain(std::string level) {

	size_t i;
	for (i = 0; i < 4 && this->pairs[i].m_name != level; ++i) {};
	if (i == 4) {
		std::cout << "[EMPTY]" << std::endl;
		std::cout << "There is no words in the world to "
					 "describe this situation!" << std::endl;
	}
	else {
		(this->*pairs[i].member)();
	}
}

void	Harl::debug(void) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my "
				 "XL-double-cheese-triple-pickle-special-ketchup burger. "
				 "I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
				 "You didn’t put enough bacon in my burger! If you did, "
				 "I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
				 "I’ve been coming for years whereas you started working "
				 "here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}
