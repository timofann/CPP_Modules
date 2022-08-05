#include "Harl.h"
#include <iostream>

//t_pair *Harl::pairs = {{"debug", this.debug},
//					   {"info", this.info},
//					   {"warning", this.warning},
//					   {"error", this.error}};

Harl::Harl(void) {
	pairs[0].f_name = "debug";
	pairs[0].handler = &debug;
	pairs[1].f_name = "info";
	pairs[1].handler = &info;
	pairs[2].f_name = "warning";
	pairs[2].handler = &warning;
	pairs[3].f_name = "error";
	pairs[3].handler = &error;
}

Harl::~Harl(void) {}

void	Harl::complain(std::string level) {
	size_t i = 0;
	while (pairs[i++].f_name != level);
	pairs[i].handler();
}

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my "
				 "XL-double-cheese-triple-pickle-special- ketchup burger. "
				 "I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. "
				 "You didn’t put enough bacon in my burger! If you did, "
				 "I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. "
				 "I’ve been coming for years whereas you started working "
				 "here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}
