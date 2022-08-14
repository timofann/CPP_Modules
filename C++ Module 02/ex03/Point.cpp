/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:30:57 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/14 12:30:58 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"
#include <iostream>

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {
	std::cout << "\033[3;36mPoint \033[3;37m"
			  << "default constructor called"
	          << "\033[0m" << std::endl;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {
	std::cout << "\033[3;36mPoint \033[3;37m"
	          << "floating-point constructor called"
	          << "\033[0m" << std::endl;
}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y) {
	std::cout << "\033[3;36mPoint \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
}

Point::~Point(void) {
	std::cout << "\033[3;36mPoint \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
}

Point   &Point::operator=(const Point &assign) {
	std::cout << "\033[3;36mPoint \033[3;37m"
	          << "copy assignment operator called"
	          << "\033[0m" << std::endl;
	const_cast<Fixed &>(this->_x) = assign._x;
	const_cast<Fixed &>(this->_y) = assign._y;
	return *this;
}

const Fixed   Point::x(void) const {
	return this->_x;
}

const Fixed   Point::y(void) const {
	return this->_y;
}

