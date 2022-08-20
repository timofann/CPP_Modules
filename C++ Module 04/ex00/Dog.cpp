/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:38:55 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/20 17:38:56 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal(), type_("dog") {
	std::cout << "\033[3;36mDog \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy), type_(copy.type_) {
	std::cout << "\033[3;36mDog \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
}

Dog::~Dog() {
	std::cout << "\033[3;36mDog \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "\033[3;36mDog \033[3;37m"
	          << "copy assignment operator called"
	          << "\033[0m" << std::endl;
	if (this == &other)
		return *this;
	Animal::operator=(other);
	this->type_ = other.type_;
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