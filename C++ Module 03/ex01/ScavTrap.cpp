/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:57:29 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/16 17:37:28 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "\033[3;36mScavTrap \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
	this->hit_points_ = 100;
	this->energy_points_ = 50;
	this->attack_damage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	std::cout << "\033[3;36mScavTrap \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "\033[3;36mScavTrap \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
}

void        ScavTrap::attack(const std::string &target) {
	if (this->isOutOfEnergy() || this->isOutOfHitPoints())
		return;
	std::cout << "\033[3;36mScavTrap "
	          << this->name_ << " attacks " << target
	          << " causing " << this->attack_damage_ << " points of damage!"
	          << "\033[0m" << std::endl;
	--this->energy_points_;
}

void        ScavTrap::guardGate(void) {
	std::cout << "\033[3;36mScavTrap "
	          << this->name_ << " is now in Gate keeper mode"
			  << "\033[0m" << std::endl;
}

