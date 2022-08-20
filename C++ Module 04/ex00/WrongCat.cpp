/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:43:12 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/20 19:43:14 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(), type_("wrong_cat") {
	std::cout << "\033[3;31mWrongCat \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) :
									WrongAnimal(copy),
									type_(copy.type_) {
	std::cout << "\033[3;31mWrongCat \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "\033[3;31mWrongCat \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "\033[3;31mWrongCat \033[3;37m"
	          << "copy assignment operator called"
	          << "\033[0m" << std::endl;
	if (this == &other)
		return *this;
	WrongAnimal::operator=(other);
	this->type_ = other.type_;
	return *this;
}

void    WrongCat::makeSound(void) const {
	std::cout << "\033[3;31mWrongCat "
	          << "Meooooooooooowwwwwwwwwwwwwwww"
	          << "\033[0m" << std::endl;
}

std::string     WrongCat::getType(void) const {
	return this->type_;
}