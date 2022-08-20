#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << ((Dog *)dog)->getType() << " " << std::endl;
	std::cout << ((Cat *)cat)->getType() << " " << std::endl;
//	std::cout << ((Cat *)dog)->getType() << " " << std::endl;
//	std::cout << ((Dog *)cat)->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl;
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();
	std::cout << wcat->getType() << " " << std::endl;
	std::cout << ((WrongCat *)wcat)->getType() << " " << std::endl;
	wcat->makeSound();
	wmeta->makeSound();

	delete wmeta;
	delete wcat;

	return 0;
}
