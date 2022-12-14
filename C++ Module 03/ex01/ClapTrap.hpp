/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:20:18 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/16 17:37:21 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class   ClapTrap {

protected:
	std::string     name_;
	unsigned int    hit_points_;
	unsigned int    energy_points_;
	unsigned int    attack_damage_;
	bool            isOutOfEnergy(void) const;
	bool            isOutOfHitPoints(void) const;

public:
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &copy);
	~ClapTrap(void);
	ClapTrap &operator=(const ClapTrap &other);
	void            attack(const std::string& target);
	void            takeDamage(unsigned int amount);
	void            beRepaired(unsigned int amount);
};

#endif
