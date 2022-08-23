#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
	std::cout << "\033[3;36mCure \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy.type_) {
	std::cout << "\033[3;36mCure \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
}

Cure::~Cure(void) {
	std::cout << "\033[3;36mCure \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	std::cout << "\033[3;36mCure \033[3;37m"
	          << "This code will never be running!"
	          << "\033[0m" << std::endl;
	if (this != &other)
		this->type_ = other.type_;
	return *this;
}

Cure *Cure::clone(void) const {
	return new Cure();
}

void Cure::use(ICharacter &target) const {
	std::cout << "\033[3;36mCure "
	          << "* heals " << target.getName() << "’s wounds *"
	          << "\033[0m" << std::endl;
}
