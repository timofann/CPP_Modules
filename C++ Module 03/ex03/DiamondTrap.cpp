/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:28:02 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/16 18:28:03 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) :
									ClapTrap(name + "_clap_name"),
									ScavTrap(name + "_scav_name"),
									FragTrap(name + "_frag_name") {
	std::cout << "\033[3;31mDIAMONDTRAP \033[3;37m"
	          << "CONSTRUCTOR CALLED"
	          << "\033[0m" << std::endl;
	this->name_ = name;
	this->hit_points_ = FragTrap::hit_points_;
	this->energy_points_ = ScavTrap::energy_points_;
	this->attack_damage_ = FragTrap::attack_damage_;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) :
									ClapTrap(copy.name_ + "_clap_name"),
									ScavTrap(copy.name_ + "_scav_name"),
									FragTrap(copy.name_ + "_frag_name") {
	std::cout << "\033[3;31mDIAMONDTRAP \033[3;37m"
	          << "COPY CONSTRUCTOR CALLED"
	          << "\033[0m" << std::endl;
	this->name_ = copy.name_;
	this->hit_points_ = copy.hit_points_;
	this->energy_points_ = copy.energy_points_;
	this->attack_damage_ = copy.attack_damage_;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "\033[3;31mDIAMONDTRAP \033[3;37m"
	          << "DESTRUCTOR CALLED"
	          << "\033[0m" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "\033[3;31mDIAMONDTRAP \033[3;37m"
	          << "COPY ASSIGNMENT OPERATOR CALLED"
	          << "\033[0m" << std::endl;
	if (this == &other)
		return *this;
	ClapTrap::operator = (other);
	this->name_ = other.name_;
	return *this;
}

void    DiamondTrap::whoAmI(void) {
	std::cout << "\033[3;31mDIAMONDTRAP "
	          << this->name_ << " 'I'm derived of " << ClapTrap::name_ << "!'"
	          << "\033[0m" << std::endl;
}
