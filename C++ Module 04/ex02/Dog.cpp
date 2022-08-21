/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:38:55 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/21 18:56:59 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal(), brain_(new Brain()), type_("dog") {
	std::cout << "\033[3;36mDog \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy),
                            brain_(new Brain()),
							type_(copy.type_) {
	std::cout << "\033[3;36mDog \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
	int ideas_num = copy.brain_->getIdeasNum();
	for (int i = 0; i < ideas_num; ++i)
		this->brain_->addIdea(copy.brain_->getIdea(i));
}

Dog::~Dog() {
	std::cout << "\033[3;36mDog \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
	delete this->brain_;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "\033[3;36mDog \033[3;37m"
	          << "copy assignment operator called"
	          << "\033[0m" << std::endl;
	if (this == &other)
		return *this;
	Animal::operator=(other);
	this->type_ = other.type_;
	this->brain_->setIdeasNum(0);
	int ideas_num = other.brain_->getIdeasNum();
	for (int i = 0; i < ideas_num; ++i)
		this->brain_->addIdea(other.brain_->getIdea(i));
	return *this;
}

void    Dog::makeSound(void) const {
	std::cout << "\033[3;36mDog "
	          << "Bark-bark!"
	          << "\033[0m" << std::endl;
}

std::string     Dog::getType(void) const {
	return this->type_;
}

void    Dog::printIdeas(void) {
	int ideas_num = this->brain_->getIdeasNum();
	for (int i = 0; i < ideas_num; ++i) {
		std::cout << "\033[3;36mDog "
		          << this->brain_->getIdea(i)
		          << "\033[0m" << std::endl;
	}
	if (ideas_num == 0) {
		std::cout << "\033[3;36mDog \033[3;37m"
		          << "No ideas right now. I'm hungry."
		          << "\033[0m" << std::endl;
	}
}

void    Dog::addIdea(std::string idea) {
	this->brain_->addIdea(idea);
}