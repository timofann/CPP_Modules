/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:51:44 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/03 20:51:44 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

Zombie*	newZombie(std::string _name) {
	try {
		Zombie* new_zombie = new Zombie(_name);
		return (new_zombie);
	}
	catch (std::bad_alloc err) {
		std::cerr << "Bad allocation" << std::endl;
		return NULL;
	}
}