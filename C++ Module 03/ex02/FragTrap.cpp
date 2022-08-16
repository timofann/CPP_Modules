/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:03:53 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/16 18:03:59 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "\033[3;32mFragTrap \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
	this->hit_points_ = 100;
	this->energy_points_ = 100;
	this->attack_damage_ = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	std::cout << "\033[3;32mFragTrap \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "\033[3;32mFragTrap \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
}

void    FragTrap::highFivesGuys(void) {
	std::cout << "\033[3;32mFragTrap "
	          << this->name_ << " 'Hey Guys! It's time to high five!'"
	          << "\033[0m" << std::endl;
}

