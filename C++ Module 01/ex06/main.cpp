#include "Harl.h"
#include <iostream>

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Usage : ./harlFilter <complain_lvl>" << std::endl;
		return 0;
	}
	Harl harl(argv[1]);

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
