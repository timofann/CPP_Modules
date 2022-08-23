/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:42:58 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/20 19:43:01 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type_("wrong_animal") {
	std::cout << "\033[3;31mWrongAnimal \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type_(copy.type_) {
	std::cout << "\033[3;31mWrongAnimal \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "\033[3;31mWrongAnimal \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "\033[3;31mWrongAnimal \033[3;37m"
	          << "copy assignment operator called"
	          << "\033[0m" << std::endl;
	if (this != &other)
		this->type_ = other.type_;
	return *this;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "\033[3;31mWrongAnimal "
	          << "MewteberkawMoChickChibbrr"
	          << "\033[0m" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return this->type_;
}
