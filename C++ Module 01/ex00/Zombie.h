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
	Zombie*	newZombie(std::string _name);
	void	randomChump(std::string _name);

private:
	std::string	name;
};

#endif
