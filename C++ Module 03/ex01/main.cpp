/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:14:24 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/16 17:37:23 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main(void) {

	ScavTrap will("Will");
	ScavTrap john("John");
	will.guardGate();
	will.beRepaired(10);
	john.attack("Will");
	will.takeDamage(20);

	ScavTrap mona = john;
	std::cout << "(Mona) ";
	mona.attack("John");
	john.takeDamage(20);
	john.attack("Mona");
	std::cout << "(Mona) ";
	mona.takeDamage(20);

	mona = will;
	std::cout << "(Mona) ";
	mona.beRepaired(100);

	ScavTrap greg(mona);
	std::cout << "(Greg) ";
	greg.guardGate();
	std::cout << "(Greg) ";
	greg.beRepaired(100);

	return 0;
}