/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:27:58 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/16 18:27:59 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

class DiamondTrap : public ScavTrap, public FragTrap {

private:
	std::string name_;

public:
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &copy);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &other);
	void        whoAmI(void);
	using       FragTrap::attack;
};

#endif
