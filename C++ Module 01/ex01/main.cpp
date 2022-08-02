#include "Zombie.h"

int	main(void) {
	size_t	zombie_nbr = 4;
	Zombie *horde = zombieHorde(zombie_nbr, "Alice");
	for (size_t i = 0; i < zombie_nbr; i++) {
		horde[i].announce();
	}
	delete[] horde;
}