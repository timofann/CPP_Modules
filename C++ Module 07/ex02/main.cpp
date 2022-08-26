#include "Array.hpp"
#include <iostream>

int main() {

	Array<int> emptyintarr;
	std::cout << "\033[37mSize of empty: " << emptyintarr.size() << "\033[0m" << std::endl;
	Array<int> filledintarr(3);
	std::cout << "\033[37mSize of filled: " << filledintarr.size() << "\033[0m" << std::endl;

	std::cout << "\033[36m" << filledintarr << "\033[0m" << std::endl;
	filledintarr[0] = 3;
	filledintarr[1] = 4;
	filledintarr[2] = 5;
	std::cout << "\033[35m" << filledintarr << "\033[0m" << std::endl;

	Array<int> filledintarrcopy1(filledintarr);
	std::cout << "\033[32m" << filledintarrcopy1 << "\033[0m" << std::endl;
	Array<int> filledintarrcopy2;
	filledintarrcopy2 = filledintarr;
	std::cout << "\033[34m" << filledintarrcopy2 << "\033[0m" << std::endl;
	// Leaks check
	filledintarrcopy2 = emptyintarr;
	std::cout << "\033[34m" << filledintarrcopy2 << "\033[0m" << std::endl;

	try {
		std::cout << emptyintarr[0] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	//	Array<float> filledfloatarr1(filledintarr); // compilation error
}

