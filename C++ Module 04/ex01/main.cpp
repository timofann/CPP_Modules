/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:55:06 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/21 18:57:11 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>


int main(void) {

	Animal *animals[20];
	for (int i = 0; i < 10; i += 2) {
		animals[i] = new Cat();
		animals[i + 1] = new Dog();
	}

	animals[0]->makeSound();
	((Cat *)(animals[0]))->printIdeas();
//	((Dog *)(animals[0]))->printIdeas();
	((Cat *)(animals[0]))->addIdea("Delicious fish!");
	((Cat *)(animals[0]))->addIdea("This IS A BIRD! LOOK! THIS IS A BIRD!");
	((Cat *)(animals[0]))->printIdeas();
//	((Dog *)(animals[0]))->printIdeas();

	animals[1]->makeSound();

	*(animals[0]) = Dog();
	animals[0]->makeSound();
//	((Dog *)(animals[0]))->printIdeas();

	*(animals[0]) = Cat();
//	((Dog *)(animals[0]))->printIdeas();

	for (int i = 0; i < 10; i += 2) {
		((Cat *)(animals[i]))->addIdea("first_cat_idea");
		((Cat *)(animals[i]))->addIdea("second_cat_idea");
		((Dog *)(animals[i + 1]))->addIdea("first_dog_idea");
		((Dog *)(animals[i + 1]))->addIdea("second_dog_idea");
	}

	for (int i = 0; i < 10; ++i) {
		delete animals[i];
	}

	Animal *cat = new Cat;
	((Cat *)cat)->addIdea("first");
	((Cat *)cat)->printIdeas();
	(*cat).makeSound();
	*cat = Cat();
//	*cat = Dog();
	((Cat *)cat)->printIdeas();
	delete cat;

	Cat cat1;
	Cat cat2;
	cat1.addIdea("there_is_an_idea");
	cat2 = cat1;
	cat1.addIdea("there_is_one_more_idea_here");
	std::cout << "cat1" << std::endl;
	cat1.printIdeas();
	std::cout << "cat2" << std::endl;
	cat2.printIdeas();

	return 0;
}
