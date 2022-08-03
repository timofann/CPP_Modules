/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:52:35 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/03 20:52:35 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie*	zombieHorde(int n, std::string _name) {
	if (n < 0) {
		std::cout << "Need more zombieeezzzzzZ" << std::endl;
		return NULL;
	}
	try {
		Zombie* horde = new Zombie[n];
		for (int i = 0; i < n; i++) {
			horde[i] = Zombie(_name);
		}
		return horde;
	}
	catch (std::bad_alloc err) {
		std::cerr << "Bad allocation" << std::endl;
		return NULL;
	}
}
