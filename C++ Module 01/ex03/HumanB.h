/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:53:10 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/04 04:25:25 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"
#include <string>

class	HumanB {

public:
	HumanB(std::string _name);
	~HumanB(void);
	void	attack(void);
	void	setWeapon(Weapon &_weapon);

private:
	HumanB(void);
	Weapon		*weapon;
	std::string	name;
};

#endif
