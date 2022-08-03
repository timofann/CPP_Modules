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

HumanB::HumanB(void) {
	std::cout << "\033[3;37m"
			  << "HumanB default constructor called"
			  << "\033[0m" << std::endl;
	this->name = "";
}

HumanB::HumanB(std::string _name, Weapon _weapon) {
	this->name = _name;
	this->weapon = _weapon;
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
	this->weapon = _weapon;
}

void HumanB::attack(void) {
	std::cout << "\033[3;31m"
			  << this->name << " attacks with their "
			  << this->weapon.getType()
			  << "\033[0m" << std::endl;
}