#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"
#include <string>

class	HumanB {

public:
	HumanB(std::string _name);
	HumanB(std::string _name, Weapon _weapon);
	~HumanB(void);
	void	attack(void);
	void	setWeapon(Weapon _weapon);

private:
	HumanB(void);
	Weapon		weapon;
	std::string	name;
};

#endif
