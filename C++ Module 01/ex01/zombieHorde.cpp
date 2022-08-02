#include "Zombie.h"

Zombie*	zombieHorde(int n, std::string _name) {
	try {
		Zombie* horde = new Zombie[n];
		for (size_t i = 0; i < N; i++) {
			(*horde)[i] = Zombie(_name);
		}
		return horde;
	}
	catch (std::bad_alloc err) {
		std::cerr << "Bad allocation" << std::endl;
		return NULL;
	}
}
