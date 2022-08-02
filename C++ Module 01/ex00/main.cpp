#include "Zombie.h"

int	main(void) {
	Zombie my_first_zombie;
	my_first_zombie = Zombie("FirstZombiePoul");
	my_first_zombie.announce();

	Zombie my_second_zombie = Zombie("SecondZombieJacob");
	my_second_zombie.announce();

	randomChump("ThirdZombieSousanna");

	Zombie my_fourth_zombie("FourthZombieTom");
	my_fourth_zombie.announce();

	Zombie *my_fifth_zombie = newZombie("FifthZombieKate");
	my_fifth_zombie->announce();
	delete my_fifth_zombie;
}
