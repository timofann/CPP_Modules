/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:07:33 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/21 18:56:50 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain() {
	std::cout << "\033[3;34mBrain \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
	this->ideas_num_ = 0;
}

Brain::Brain(const Brain &copy) {
	std::cout << "\033[3;34mBrain \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
	for (int i = 0; i < MAX_IDEAS_COUNT; ++i)
		this->ideas_[i] = copy.ideas_[i];
	this->ideas_num_ = copy.ideas_num_;
}

Brain::~Brain() {
	std::cout << "\033[3;34mBrain \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "\033[3;34mBrain \033[3;37m"
	          << "copy assignment operator called"
	          << "\033[0m" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < MAX_IDEAS_COUNT; ++i)
		this->ideas_[i] = other.ideas_[i];
	this->ideas_num_ = other.ideas_num_;
	return *this;
}

void Brain::addIdea(const std::string &idea) {
	if (this->ideas_num_ == MAX_IDEAS_COUNT) {
		for (int i = 0; i < MAX_IDEAS_COUNT - 1; ++i)
			this->ideas_[i] = this->ideas_[i + 1];
		this->ideas_[MAX_IDEAS_COUNT - 1] = idea;
	}
	else {
		this->ideas_[ideas_num_] = idea;
		this->ideas_num_ += 1;
	}
}

std::string Brain::getIdea(int i) {
	if (i < 0 || i >= MAX_IDEAS_COUNT)
		return "Mind's infinity is too abstract to perform";
	if (i >= this->ideas_num_)
		return "Empty spaaace O_o";
	return this->ideas_[i];
}

int Brain::getIdeasNum(void) {
	return this->ideas_num_;
}

void Brain::setIdeasNum(int num) {
	this->ideas_num_ = num;
}