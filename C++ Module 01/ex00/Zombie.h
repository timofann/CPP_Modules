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

Zombie*	newZombie(std::string _name);
void	randomChump(std::string _name);

#endif
