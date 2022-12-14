#include "Base.hpp"
#include "time.h"
#include <iostream>
#include <unistd.h>

Base *generate() {
	std::time_t now = std::time(NULL);
	int randint = now % 3;
	switch (randint) {
		case 0 : {
			std::cout << "\033[3;36mA-class' instance has generated\033[0m" << std::endl;
			return (new A());
		}
		case 1 : {
			std::cout << "\033[3;35mB-class' instance has generated\033[0m" << std::endl;
			return (new B());
		}
		default : {
			std::cout << "\033[3;32mC-class' instance has generated\033[0m" << std::endl;
			return (new C());
		}
	}
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << "\033[3;36mPointer to A identified successfully\033[0m" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "\033[3;35mPointer to B identified successfully\033[0m" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "\033[3;32mPointer to C identified successfully\033[0m" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "\033[3;36mA-class instance identified successfully\033[0m" << std::endl;
	} catch (...) {
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << "\033[3;35mB-class instance identified successfully\033[0m" << std::endl;
		} catch (...) {
			std::cout << "\033[3;32mC-class instance identified successfully\033[0m" << std::endl;
		}
	}
}

int main() {

	Base *b1 = generate();
	identify(b1);
	identify(*b1);

	usleep(1500000);

	Base *b2 = generate();
	identify(b2);
	identify(*b2);

	usleep(900000);

	Base *b3 = generate();
	identify(b3);
	identify(*b3);

	delete b1;
	delete b2;
	delete b3;
}