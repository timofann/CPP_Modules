#include "Zombie.h"
#include <iostream>
#include <string>

Zombie::Zombie(void) {
	std::cout << "\033[3;37m"
			  << "Zombie default constructor called"
			  << "\033[0m" << std::endl;
}

Zombie::Zombie(std::string _name) {
	this->name = _name;

	std::cout << "\033[3;37m"
			  << "Zombie constructor called for the next instance:"
			  << std::endl;
	std::cout << "ZombieName: " << this->name
	          << "\033[0m" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "\033[3;37m"
			  << "Zombie destructor called for the next instance:"
			  << std::endl;
	std::cout << "ZombieName: " << this->name
	          << "\033[0m" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << "\033[3;31m" << this->name << ": BraiiiiiiinnnzzzZ..."
			  << "\033[0m" << std::endl;
}
