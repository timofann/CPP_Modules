#include "Weapon.h"
#include <iostream>

Weapon::Weapon(void) {
	std::cout << "\033[3;37m"
			  << "Weapon default constructor called"
			  << "\033[0m" << std::endl;
	this->type = "";
}

Weapon::Weapon(std::string _type) {
	this->type = _type;

	std::cout << "\033[3;37m"
			  << "Weapon constructor called for the next instance:"
			  << std::endl;
	std::cout << "WeaponType: " << this->type
			  << "\033[0m" << std::endl;
}

Weapon::~Weapon() {
	std::cout << "\033[3;37m"
			  << "Weapon destructor called for the next instance:"
			  << std::endl;
	std::cout << "WeaponType: " << this->type
			  << "\033[0m" << std::endl;
}

const std::string	&Weapon::getType(void) {
	const std::string &type_ref = this->type;
	return type_ref;
}

void	Weapon::setType(std::string _type) {
	this->type = _type;
}



