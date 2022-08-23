#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {
	std::cout << "\033[3;32mIce \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy.type_) {
	std::cout << "\033[3;32mIce \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
}

Ice::~Ice(void) {
	std::cout << "\033[3;32mIce \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	std::cout << "\033[3;32mIce \033[3;37m"
	          << "This code will never be running!"
	          << "\033[0m" << std::endl;
	if (this != &other)
		this->type_ = other.type_;
	return *this;
}

Ice *Ice::clone(void) const {
	return new Ice();
}

void Ice::use(ICharacter &target) const {
	std::cout << "\033[3;32mIce "
	          << "* shoots an ice bolt at " << target.getName() << " *"
	          << "\033[0m" << std::endl;
}
