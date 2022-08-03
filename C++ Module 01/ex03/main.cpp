/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:53:17 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/03 20:53:17 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"
#include "HumanB.h"
#include "HumanA.h"

int main(void) {
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
//	Weapon  club = Weapon("crude spiked club");
//	HumanB jim("Jim");
//	jim.setWeapon(club);
//	jim.attack();
//	club.setType("some other type of club");
//	jim.attack();
}