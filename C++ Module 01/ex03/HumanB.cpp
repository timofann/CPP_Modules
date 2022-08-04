/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:53:04 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/03 20:53:04 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"
#include "Weapon.h"
#include <iostream>

HumanB::HumanB(std::string _name) {
	this->name = _name;
	this->weapon = nullptr;
	std::cout << "\033[3;37m"
			  << "HumanB constructor called for the next instance:"
			  << std::endl;
	std::cout << "HumanName: " << this->name
			  << "\033[0m" << std::endl;
}

HumanB::~HumanB(void) {
	std::string	weapon_type;
	if (this->weapon == nullptr)
		weapon_type = "empty hands";
	else
		weapon_type = this->weapon->getType();

	std::cout << "\033[3;37m"
			  << "HumanB destructor called for the next instance:"
			  << std::endl;
	std::cout << "HumanName: " << this->name
			  << std::endl;
	std::cout << "WeaponType: " << weapon_type
			  << "\033[0m" << std::endl;
}

void	HumanB::setWeapon(Weapon &_weapon) {
	this->weapon = &_weapon;
}

void HumanB::attack(void) {
	std::string	weapon_type;
	if (this->weapon == nullptr)
		weapon_type = "empty hands";
	else
		weapon_type = this->weapon->getType();

	std::cout << "\033[3;31m"
			  << this->name << " attacks with their "
			  << weapon_type
			  << "\033[0m" << std::endl;
}