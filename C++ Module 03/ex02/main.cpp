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
#include "FragTrap.hpp"

int main(void) {

	FragTrap august("August");
	FragTrap george("George");

	FragTrap sophie("Sophie");
	sophie.highFivesGuys();

	august.beRepaired(20000);
	george.beRepaired(20000);
	sophie.beRepaired(20000);

	FragTrap steve(sophie);
	std::cout << "(Steve) ";
	steve.highFivesGuys();

	august.beRepaired(40000);
	george.beRepaired(40000);
	sophie.beRepaired(40000);
	std::cout << "(Steve) ";
	steve.beRepaired(40000);

	steve = august;
	std::cout << "(Steve) ";
	steve.highFivesGuys();

	return 0;
}