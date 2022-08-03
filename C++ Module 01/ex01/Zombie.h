/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:52:29 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/03 20:52:29 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class	Zombie {

public:
	Zombie(void);
	Zombie(std::string _name);
	~Zombie(void);

	void	announce(void);

private:
	std::string	name;
};

Zombie*	zombieHorde(int n, std::string _name);

#endif
