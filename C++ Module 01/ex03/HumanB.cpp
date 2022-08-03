#include "HumanB.h"
#include "Weapon.h"
#include <iostream>

HumanB::HumanB(void) {
	std::cout << "\033[3;37m"
			  << "HumanB default constructor called"
			  << "\033[0m" << std::endl;
	this->name = "";
}

HumanB::HumanB(std::string _name, Weapon _weapon) {
	this->name = _name;
	this->weapon.setType(_weapon);
	std::cout << "\033[3;37m"
			  << "HumanB constructor called for the next instance:"
			  << std::endl;
	std::cout << "HumanName: " << this->name
			  << std::endl;
	std::cout << "WeaponType: " << this->weapon.getType()
			  << "\033[0m" << std::endl;
}

HumanB::HumanB(std::string _name) {
	this->name = _name;
	std::cout << "\033[3;37m"
			  << "HumanB constructor called for the next instance:"
			  << std::endl;
	std::cout << "HumanName: " << this->name
			  << "\033[0m" << std::endl;
}

HumanB::~HumanB(void) {
	std::cout << "\033[3;37m"
			  << "HumanB destructor called for the next instance:"
			  << std::endl;
	std::cout << "HumanName: " << this->name
			  << std::endl;
	std::cout << "WeaponType: " << this->weapon.getType()
			  << "\033[0m" << std::endl;
}

void	HumanB::setWeapon(Weapon _weapon) {
	this->weapon.setType(_weapon.getType());
}

void HumanB::attack(void) {
	std::cout << "\033[3;31m"
			  << this->name << " attacks with their "
			  << this->weapon.getType()
			  << "\033[0m" << std::endl;
}