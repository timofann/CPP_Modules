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
#include "DiamondTrap.hpp"

int main(void) {

	DiamondTrap sam("Sam");
	sam.whoAmI();
	sam.beRepaired(1);
	sam.takeDamage(0);
	sam.attack("Bob");
	sam.highFivesGuys();
	sam.guardGate();

	DiamondTrap din("Din");
	din.beRepaired(100);
	din = sam;
	std::cout << "(Din) ";
	din.beRepaired(1);
	std::cout << "(Din) ";
	din.whoAmI();

	return 0;
}