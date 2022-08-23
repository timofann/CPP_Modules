#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) : type_(type) {
	std::cout << "\033[3;35mAMateria \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
}

AMateria::AMateria(const AMateria &copy) : type_(copy.type_) {
	std::cout << "\033[3;35mAMateria \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
}

AMateria::~AMateria(void) {
	std::cout << "\033[3;35mAMateria \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
	std::cout << "\033[3;35mAMateria \033[3;37m"
	          << "copy assignment operator called"
	          << "\033[0m" << std::endl;
	if (this != &other)
		this->type_ = other.type_;

	return *this;
}

std::string const &AMateria::getType(void) const {
	return this->type_;
}

void AMateria::use(ICharacter &target) const {
	(void)target;
	std::cout << "This code will never be running!" << std::endl;
}
