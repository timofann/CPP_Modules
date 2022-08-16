/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:14:24 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/15 23:14:46 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void) {

	ClapTrap bob("Bob");
	ClapTrap ron("Ron");

	bob.attack("Ron");
	ron.takeDamage(10);
	ron.beRepaired(100);
	bob.beRepaired(4294967294);

	ClapTrap jina("Jina");
	jina = bob;
	bob.attack("Jina");
	std::cout << "(Jina) ";
	jina.takeDamage(4294967294);
	jina = ron;
	std::cout << "(Jina) ";
	jina.beRepaired(10);

	ClapTrap sid(bob);
	bob.attack("Sid");
	std::cout << "(Sid) ";
	sid.takeDamage(4294967294);
	std::cout << "(Sid) ";
	sid.beRepaired(10);

	sid = jina;
	std::cout << "(Sid) ";
	sid.attack("Bob");

	return 0;
}