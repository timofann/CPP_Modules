/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:52:51 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/03 20:52:51 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"
#include "Weapon.h"
#include <iostream>

HumanA::HumanA(std::string _name, Weapon &_weapon) : weapon(_weapon) {
	this->name = _name;
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

void HumanA::attack(void) {
	std::cout << "\033[3;31m"
	          << this->name << " attacks with their "
			  << this->weapon.getType()
			  << "\033[0m" << std::endl;
}