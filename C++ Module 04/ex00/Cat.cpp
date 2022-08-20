/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:38:55 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/20 17:38:56 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal(), type_("cat") {
	std::cout << "\033[3;32mCat \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy), type_(copy.type_) {
	std::cout << "\033[3;32mCat \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
}

Cat::~Cat() {
	std::cout << "\033[3;32mCat \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "\033[3;32mCat \033[3;37m"
	          << "copy assignment operator called"
	          << "\033[0m" << std::endl;
	if (this == &other)
		return *this;
	Animal::operator=(other);
	this->type_ = other.type_;
	return *this;
}

void    Cat::makeSound(void) const {
	std::cout << "\033[3;32mCat "
	          << "Meooooooooooowwwwwwwwwwwwwwww"
	          << "\033[0m" << std::endl;
}

std::string     Cat::getType(void) const {
	return this->type_;
}