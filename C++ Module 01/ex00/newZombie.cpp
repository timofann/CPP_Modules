#include "Zombie.h"
#include <iostream>

Zombie*	newZombie(std::string _name) {
	try {
		Zombie* new_zombie = new Zombie(_name);
		return (new_zombie);
	}
	catch (std::bad_alloc err) {
		std::cerr << "Bad allocation" << std::endl;
		return (NULL);
	}
}