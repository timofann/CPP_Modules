#include "Iter.hpp"

int main() {

	const int   arr1[] = { 0, 1, 2, 3, 4 };
	std::string arr2[] = { "00", "01", "02", "03", "04" };

	std::cout << "\033[35mInteger:" << std::endl;
	iter(arr1, 5, printInstance);
	std::cout << "\033[36mString:" << std::endl;
	iter(arr2, 5, printInstance);
	return 0;
}
