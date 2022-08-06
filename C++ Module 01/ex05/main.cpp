#include "Harl.h"
#include <iostream>

int main(void) {
	Harl harl;

	std::cout << "\033[3;35m";
	harl.complain("DEBUG");
	std::cout << "\033[3;34m";
	harl.complain("INFO");
	std::cout << "\033[3;36m";
	harl.complain("WARNING");
	std::cout << "\033[3;32m";
	harl.complain("ERROR");
	std::cout << "\033[3;33m";
	harl.complain("DEDELMIR");
	std::cout << "\033[0m";
}
