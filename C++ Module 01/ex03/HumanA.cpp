#include "HumanA.h"
#include "Weapon.h"
#include <iostream>

HumanA::HumanA(void) {
	std::cout << "\033[3;37m"
			  << "HumanA default constructor called"
			  << "\033[0m" << std::endl;
	this->weapon = Weapon("");
	this->name = "";
}

HumanA::HumanA(std::string _name, Weapon _weapon) {
	this->name = _name;
	this->weapon = _weapon;
	std::cout << "\033[3;37m"
			  << "HumanA constructor called for the next instance:"
			  << std::endl;
	std::cout << "HumanName: " << this->name
			  << std::endl;
	std::cout << "WeaponType: " << this->weapon.getType()
			  << "\033[0m" << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << "\033[3;37m"
			  << "HumanA destructor called for the next instance:"
			  << std::endl;
	std::cout << "HumanName: " << this->name
			  << std::endl;
	std::cout << "WeaponType: " << this->weapon.getType()
			  << "\033[0m" << std::endl;
}

void	setWeapon(Weapon _weapon) {

}

void HumanA::attack(void) {
	std::cout << "\033[3;31m"
	          << this->name << " attacks with their "
			  << this->weapon.getType()
			  << "\033[0m" << std::endl;
}