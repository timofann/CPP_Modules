/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:52:57 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/04 04:25:10 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include <string>

class	HumanA {

public:
	HumanA(std::string _name, Weapon &_weapon);
	~HumanA(void);
	void	attack(void);

private:
	HumanA(void);
	Weapon		&weapon;
	std::string	name;
};

#endif
