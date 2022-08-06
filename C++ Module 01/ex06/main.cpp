#include "Harl.h"
#include <iostream>

int main(void) {
	Harl harl;

	std::cout << "\033[3;35m";
	harl.complain("debug");
	std::cout << "\033[3;34m";
	harl.complain("info");
	std::cout << "\033[3;36m";
	harl.complain("warning");
	std::cout << "\033[3;32m";
	harl.complain("error");
	std::cout << "\033[3;33m";
	harl.complain("dedelmir");
	std::cout << "\033[0m";
}
