#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class	Zombie {

public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

private:
	std::string	name;
};

#endif
