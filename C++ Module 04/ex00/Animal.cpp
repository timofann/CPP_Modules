/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:10:06 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/20 16:10:31 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal() : type_("animal") {
	std::cout << "\033[3;35mAnimal \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
}

Animal::Animal(const Animal &copy) : type_(copy.type_) {
	std::cout << "\033[3;35mAnimal \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
}

Animal::~Animal() {
	std::cout << "\033[3;35mAnimal \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
}

Animal  &Animal::operator=(const Animal &other) {
	std::cout << "\033[3;35mAnimal \033[3;37m"
	          << "copy assignment operator called"
	          << "\033[0m" << std::endl;
	if (this != &other)
		this->type_ = other.type_;
	return *this;
}

void    Animal::makeSound(void) const {
	std::cout << "\033[3;35mAnimal "
	          << "MewteberkawMoChickChibbrr"
	          << "\033[0m" << std::endl;
}

std::string     Animal::getType(void) const {
	return this->type_;
}
