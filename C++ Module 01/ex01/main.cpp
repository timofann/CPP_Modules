/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:52:16 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/03 20:52:16 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void) {
	int	zombie_nbr = 4;
	Zombie *horde = zombieHorde(zombie_nbr, "Alice");
	for (int i = 0; i < zombie_nbr; i++) {
		horde[i].announce();
	}
	delete[] horde;
}