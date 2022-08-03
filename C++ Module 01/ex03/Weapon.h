/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:53:30 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/03 21:00:53 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class	Weapon {

public:
	Weapon(void);
	Weapon(std::string _type);
	~Weapon(void);
	const std::string	&getType(void);
	void 				setType(std::string _type);

private:
	std::string	type;
};

#endif
