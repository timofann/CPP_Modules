/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:38:55 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/21 18:56:53 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal(), brain_(new Brain()), type_("cat") {
	std::cout << "\033[3;32mCat \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy),
                            brain_(new Brain()),
							type_(copy.type_) {
	std::cout << "\033[3;32mCat \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
	int ideas_num = copy.brain_->getIdeasNum();
	for (int i = 0; i < ideas_num; ++i)
		this->brain_->addIdea(copy.brain_->getIdea(i));
}

Cat::~Cat() {
	std::cout << "\033[3;32mCat \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
	delete this->brain_;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "\033[3;32mCat \033[3;37m"
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

void    Cat::makeSound(void) const {
	std::cout << "\033[3;32mCat "
	          << "Meooooooooooowwwwwwwwwwwwwwww"
	          << "\033[0m" << std::endl;
}

std::string     Cat::getType(void) const {
	return this->type_;
}

void    Cat::printIdeas(void) {
	int ideas_num = this->brain_->getIdeasNum();
	for (int i = 0; i < ideas_num; ++i) {
		std::cout << "\033[3;32mCat "
		          << this->brain_->getIdea(i)
		          << "\033[0m" << std::endl;
	}
	if (ideas_num == 0) {
		std::cout << "\033[3;32mCat \033[3;37m"
		          << "*sleep right now*"
		          << "\033[0m" << std::endl;
	}
}

void    Cat::addIdea(std::string idea) {
	this->brain_->addIdea(idea);
}