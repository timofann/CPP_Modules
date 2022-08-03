#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include <string>

class	HumanA {

public:
	HumanA(std::string _name, Weapon _weapon);
	~HumanA(void);
	void	setWeapon(Weapon _weapon);
	void	attack(void);

private:
	HumanA(void);
	Weapon		weapon;
	std::string	name;
};

#endif
