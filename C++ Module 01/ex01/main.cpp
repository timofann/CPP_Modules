#include "Zombie.h"

int	main(void) {
	int	zombie_nbr = 4;
	Zombie *horde = zombieHorde(zombie_nbr, "Alice");
	for (int i = 0; i < zombie_nbr; i++) {
		horde[i].announce();
	}
	delete[] horde;
}