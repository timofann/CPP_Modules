/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 06:12:48 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/07 06:13:42 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>
#include <cmath>

const int Fixed::_fract_size = 8;

Fixed::Fixed(void) {
    this->_value = 0;
    std::cout << "\033[3;37m"
              << "Fixed default constructor called"
              << "\033[0m" << std::endl;
}

Fixed::~Fixed(void) {
    std::cout << "\033[3;37m"
              << "Fixed destructor called"
              << "\033[0m" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &assign) {
    std::cout << "\033[3;37m"
              << "Fixed copy assignment operator called"
              << "\033[0m" << std::endl;
    this->_value = assign.getRawBits();
    return *this;
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "\033[3;37m"
              << "Fixed copy constructor called"
              << "\033[0m" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int integer_number) {
    std::cout << "\033[3;37m"
              << "Fixed integer constructor called"
              << "\033[0m" << std::endl;
//    printBits(integer_number);

    int sign = integer_number >> 31;
    if (!sign)
        this->_value = (~(Fixed::getMaxNumber(Fixed::_fract_size + 1) << 23)
				& integer_number) << Fixed::_fract_size;
    else
        this->_value = (((Fixed::getMaxNumber(Fixed::_fract_size + 1) << 23)
				| integer_number) << Fixed::_fract_size);
//    printBits(this->_value);
}

Fixed::Fixed(const float floating_point) {
    std::cout << "\033[3;37m"
              << "Fixed floating-point constructor called"
              << "\033[0m" << std::endl;
//    printBits(*((int *)(&floating_point)));
    int integer_number = (int)(floating_point);
    int fractional_part = roundf((floating_point - integer_number)
			* Fixed::getPower()) * ((integer_number >= 0) * 2 - 1);
    int sign = integer_number >> 31;
    if (!sign)
        this->_value
            = ((~(Fixed::getMaxNumber(Fixed::_fract_size + 1) << 23)
					& integer_number) << Fixed::_fract_size) | fractional_part;
    else
        this->_value
            = (((Fixed::getMaxNumber(Fixed::_fract_size + 1) << 23)
					| integer_number) << Fixed::_fract_size) | fractional_part;
//    printBits(integer_number);
//    printBits(fractional_part);
//    printBits(this->_value);
}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(const int raw) {
    this->_value = raw;
}

int     Fixed::toInt(void) const {
    int integer_number;
    integer_number = this->_value >> Fixed::_fract_size;
    return (integer_number);
}

float   Fixed::toFloat(void) const {
    float   floating_number;
    int fractional_part = this->_value & (Fixed::getMaxNumber(_fract_size));
    int integer_number = this->_value >> Fixed::_fract_size;
	int power = Fixed::getPower();
    int sign = integer_number >> 31;
    if (!sign)
        floating_number = integer_number + ((float)fractional_part / power);
    else
        floating_number = integer_number - (float)fractional_part / power;
    return (floating_number);
}

int Fixed::getMaxNumber(int mem_size) {
	int max_number = 0;
	int i = 0;
	while (i < mem_size)
	max_number |= (1 << i++);
//	std::cout << "MAX_NUMBER " << max_number << std::endl;
	return (max_number);
}

int Fixed::getPower(void) {
	int max_number = getMaxNumber(_fract_size);
	int power = 1;
	while ((max_number / power) >= 10)
		power *= 10;
//	std::cout << "POWER " << power << std::endl;
	return power;
}

int Fixed::getFractSize(void) {
	return Fixed::_fract_size;
}

void Fixed::printBits(const int bits) const {
    std::cout << "\033[37m";
    for (int i = 31; i >= 0; --i) {
        std::cout << ((bits >> i) & 1);
    }
    std::cout << "\033[0m" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Fixed &output) {
	int fractional_part = output.getRawBits()
			& (Fixed::getMaxNumber(Fixed::getFractSize()));
	int integer_number = output.getRawBits() >> Fixed::getFractSize();
	int power = Fixed::getPower() / 10;

	os << integer_number;
	if (power)
		os << ".";
	while (power > 1 && !(fractional_part / power)) {
		power /= 10;
		os << "0";
	}
	if (power)
		os << fractional_part;
	return os;
}
