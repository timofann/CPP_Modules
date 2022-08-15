/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:20:13 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/15 23:14:51 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : name_(std::string(name)),
									   hit_points_(10),
									   energy_points_(10),
									   attack_damage_(0) {
	std::cout << "\033[3;35mClapTrap \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : name_(std::string(copy.name_)),
										   hit_points_(copy.hit_points_),
										   energy_points_(copy.energy_points_),
				                           attack_damage_(copy.attack_damage_) {
	std::cout << "\033[3;35mClapTrap \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "\033[3;35mClapTrap \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assign) {
	std::cout << "\033[3;35mClapTrap \033[3;37m"
	          << "copy assignment operator called"
	          << "\033[0m" << std::endl;
	if (&assign.name_ == &(this->name_))
		return *this;
	this->name_ = std::string(assign.name_);
	this->hit_points_ = assign.hit_points_;
	this->energy_points_ = assign.energy_points_;
	this->attack_damage_ = assign.attack_damage_;
	return *this;
}

bool ClapTrap::isOutOfEnergy(void) const {
	if (this->energy_points_ == 0) {
		std::cout << "\033[3;35mClapTrap "
		          << this->name_ << " can't attack anybody right now. "
		          << "He should take a rest."
		          << "\033[0m" << std::endl;
		return true;
	}
	return false;
}

bool ClapTrap::isOutOfHitPoints(void) const {
	if (this->hit_points_ == 0) {
		std::cout << "\033[3;35mClapTrap "
		          << this->name_ << " is dead :("
		          << "\033[0m" << std::endl;
		return true;
	}
	return false;
}

void ClapTrap::attack(const std::string& target) {
	if (this->isOutOfEnergy() || this->isOutOfHitPoints())
		return;
	std::cout << "\033[3;35mClapTrap "
			  << this->name_ << " attacks " << target
			  << " causing " << this->attack_damage_ << " points of damage!"
			  << "\033[0m" << std::endl;
	--this->energy_points_;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount > this->hit_points_)
		amount = this->hit_points_;
	this->hit_points_ -= amount;
	std::cout << "\033[3;35mClapTrap "
	          << this->name_ << " got " << amount << " points of damage! "
			  << "HP left: " << this->hit_points_
	          << "\033[0m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->isOutOfEnergy() || this->isOutOfHitPoints())
		return;
	if (amount > (UINT32_MAX - this->hit_points_))
		amount = UINT32_MAX - this->hit_points_;
	this->hit_points_ += amount;
	std::cout << "\033[3;35mClapTrap "
	          << this->name_ << " repaired " << amount << " hit points! "
	          << "HP left: " << this->hit_points_
			  << "\033[0m" << std::endl;
	--this->energy_points_;
}
