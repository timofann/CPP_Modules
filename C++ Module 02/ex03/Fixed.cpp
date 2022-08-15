/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 06:12:48 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/14 13:13:35 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>
#include <cmath>

const int Fixed::_fract_size = 8;


/* ------------------------------------------------------------- CONSTRUCTORS */

Fixed::Fixed(void) {
    this->_value = 0;
    std::cout << "\033[3;35mFixed \033[3;37m"
              << "default constructor called"
              << "\033[0m" << std::endl;
}

Fixed::~Fixed(void) {
    std::cout << "\033[3;35mFixed \033[3;37m"
              << "destructor called"
              << "\033[0m" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "\033[3;35mFixed \033[3;37m"
              << "copy constructor called"
              << "\033[0m" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int integer_number) {
    std::cout << "\033[3;35mFixed \033[3;37m"
              << "integer constructor called"
              << "\033[0m" << std::endl;

	this->_value = getFixedFromParts(integer_number, 0);
}

Fixed::Fixed(const float floating_point) {
    std::cout << "\033[3;35mFixed \033[3;37m"
              << "floating-point constructor called"
              << "\033[0m" << std::endl;

    int integer_number = (int)(floating_point);
    int fractional_part = roundf((floating_point - integer_number)
			* Fixed::getPower()) * ((integer_number >= 0) * 2 - 1);

	this->_value = getFixedFromParts(integer_number, fractional_part);
}

Fixed::Fixed(const int integer_part, const int fractional_part) {
	std::cout << "\033[3;35mFixed \033[3;37m"
	          << "integer/fractional parts constructor called"
	          << "\033[0m" << std::endl;

	this->_value = getFixedFromParts(integer_part, fractional_part);
}


/* ---------------------------------------------------------------- OPERATORS */

Fixed &Fixed::operator=(const Fixed &assign) {
	std::cout << "\033[3;35mFixed \033[3;37m"
	          << "copy assignment operator called"
	          << "\033[0m" << std::endl;
	this->_value = assign.getRawBits();
	return *this;
}


/* ----------------------------------------------------- COMPARISON OPERATORS */

bool Fixed::operator<(const Fixed &right) const {
	int rfractional_part = right.getRawBits()
			& (Fixed::getMaxNumber(Fixed::_fract_size));
	int rinteger_number = right.getRawBits() >> Fixed::_fract_size;
	int lfractional_part = this->getRawBits()
			& (Fixed::getMaxNumber(Fixed::_fract_size));
	int linteger_number = this->getRawBits() >> Fixed::_fract_size;
	if (linteger_number < rinteger_number)
		return (true);
	else if (linteger_number == rinteger_number) {
		if (lfractional_part < rfractional_part)
			return (true);
	}
	return false;
}

bool Fixed::operator>(const Fixed &right) const {
	return (right < *this);
}

bool Fixed::operator==(const Fixed &right) const {
	return (!(*this < right || *this > right));
}

bool Fixed::operator!=(const Fixed &right) const {
	return (*this < right || *this > right);
}

bool Fixed::operator>=(const Fixed &right) const {
	return (!(*this < right));
}

bool Fixed::operator<=(const Fixed &right) const {
	return (!(right < *this));
}


/* ----------------------------------------------------- ARITHMETIC OPERATORS */

const Fixed Fixed::operator+(const Fixed &second_component) const {
	int sfractional_part = second_component.getRawBits()
			& (Fixed::getMaxNumber(Fixed::_fract_size));
	int sinteger_number = second_component.getRawBits() >> Fixed::_fract_size;
	int ffractional_part = this->getRawBits()
			& (Fixed::getMaxNumber(Fixed::_fract_size));
	int finteger_number = this->getRawBits() >> Fixed::_fract_size;
	int fractional_sum = ffractional_part + sfractional_part;
	int integer_sum = finteger_number + sinteger_number;
	if (fractional_sum * ((fractional_sum >= 0) * 2 - 1)
			>= Fixed::getPower()) {
		integer_sum += 1;
		fractional_sum %= Fixed::getPower();
	}
	return Fixed(integer_sum, fractional_sum);
}

const Fixed Fixed::operator-(const Fixed &second_component) const {
	int fractional_dif;
	int integer_dif;
	int sfractional_part = second_component.getRawBits()
	                       & (Fixed::getMaxNumber(Fixed::_fract_size));
	int sinteger_number = second_component.getRawBits() >> Fixed::_fract_size;
	int ffractional_part = this->getRawBits()
	                       & (Fixed::getMaxNumber(Fixed::_fract_size));
	int finteger_number = this->getRawBits() >> Fixed::_fract_size;
	integer_dif = finteger_number - sinteger_number;
	if (*this < second_component) {
		int tmp = ffractional_part;
		ffractional_part = sfractional_part;
		sfractional_part = tmp;
	}
	fractional_dif = ffractional_part - sfractional_part;
	if (fractional_dif < 0) {
		fractional_dif = Fixed::getPower()
				+ ffractional_part - sfractional_part;
		integer_dif = integer_dif - 1;
	}
	return Fixed(integer_dif, fractional_dif);
}

const Fixed Fixed::operator*(const Fixed &second_component) const {
	int sfractional_part = second_component.getRawBits()
	                       & (Fixed::getMaxNumber(Fixed::_fract_size));
	int sinteger_number = second_component.getRawBits() >> Fixed::_fract_size;
	int ffractional_part = this->getRawBits()
	                       & (Fixed::getMaxNumber(Fixed::_fract_size));
	int finteger_number = this->getRawBits() >> Fixed::_fract_size;
	int mlt = sfractional_part + sinteger_number * Fixed::getPower();
	int fractional_mlt = roundf((float)(ffractional_part * mlt)
			/ (float)Fixed::getPower());
	int integer_mlt = finteger_number * mlt;
	fractional_mlt += integer_mlt % Fixed::getPower();
	integer_mlt = integer_mlt / Fixed::getPower()
			+ fractional_mlt / Fixed::getPower();
	fractional_mlt %= Fixed::getPower();
	return Fixed(integer_mlt, fractional_mlt);
}

const Fixed Fixed::operator/(const Fixed &second_component) const {
	int sfractional_part = second_component.getRawBits()
	                       & (Fixed::getMaxNumber(Fixed::_fract_size));
	int sinteger_number = second_component.getRawBits() >> Fixed::_fract_size;
	int ffractional_part = this->getRawBits()
	                       & (Fixed::getMaxNumber(Fixed::_fract_size));
	int finteger_number = this->getRawBits() >> Fixed::_fract_size;
	int div = sfractional_part + sinteger_number * Fixed::getPower();
	int integer_div = (finteger_number * Fixed::getPower()) / div;
	int fractional_div = roundf((float)((ffractional_part
			+ ((finteger_number * Fixed::getPower()) % div))
					* Fixed::getPower()) / (float)div);
	integer_div += fractional_div / Fixed::getPower();
	fractional_div %= Fixed::getPower();
	return Fixed(integer_div, fractional_div);
}


/* ---------------------------------------------------- INCREMENT & DECREMENT */

const Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	int fractional_part = this->_value & (Fixed::getMaxNumber(_fract_size));
	int integer_number = this->_value >> Fixed::_fract_size;
	fractional_part = fractional_part + 1;
	integer_number += fractional_part / Fixed::getPower();
	fractional_part %= Fixed::getPower();

	this->_value = getFixedFromParts(integer_number, fractional_part);
	return temp;
}

Fixed &Fixed::operator++(void) {
	int fractional_part = this->_value & (Fixed::getMaxNumber(_fract_size));
	int integer_number = this->_value >> Fixed::_fract_size;
	fractional_part = fractional_part + 1;
	integer_number += fractional_part / Fixed::getPower();
	fractional_part %= Fixed::getPower();

	this->_value = getFixedFromParts(integer_number, fractional_part);
	return *this;
}

const Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	int fractional_part = this->_value & (Fixed::getMaxNumber(_fract_size));
	int integer_number = this->_value >> Fixed::_fract_size;
	fractional_part = fractional_part + Fixed::getPower() - 1;
	integer_number += fractional_part / Fixed::getPower();
	fractional_part %= Fixed::getPower();

	this->_value = getFixedFromParts(integer_number, fractional_part);
	return temp;
}

Fixed &Fixed::operator--(void) {
	int fractional_part = this->_value & (Fixed::getMaxNumber(_fract_size));
	int integer_number = this->_value >> Fixed::_fract_size;
	fractional_part = fractional_part + Fixed::getPower() - 1;
	integer_number += fractional_part / Fixed::getPower();
	fractional_part %= Fixed::getPower();

	this->_value = getFixedFromParts(integer_number, fractional_part);
	return *this;
}


/* ------------------------------------------------------------ COMPATIBILITY */

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
	if (integer_number >= 0)
		floating_number = integer_number + ((float)fractional_part / power);
	else
		floating_number = integer_number - (float)fractional_part / power;
	return (floating_number);
}

bool Fixed::isPositive(void) const {
	if (this->_value >> 31)
		return false;
	return true;
}

bool Fixed::isNegative(void) const {
	if (this->_value >> 31)
		return true;
	return false;
}

//Fixed Fixed::absoluteValue(void) const {
//	int fractional_part = this->_value & (Fixed::getMaxNumber(_fract_size));
//	int integer_number = this->_value >> Fixed::_fract_size;
//	if (integer_number < 0)
//		integer_number *= (-1);
//	return Fixed(integer_number, fractional_part);
//}


/* -------------------------------------------------------- GETTERS & SETTERS */

int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(const int raw) {
	this->_value = raw;
}

int Fixed::getFractSize(void) {
	return Fixed::_fract_size;
}

/* ------------------------------------------------------ MIN & MAX FUNCTIONS */

Fixed   &Fixed::min(Fixed &first, Fixed &second) {
	if (first <= second)
		return first;
	return second;
}

const Fixed   &Fixed::min(const Fixed &first, const Fixed &second) {
	if (first <= second)
		return first;
	return second;
}

Fixed   &Fixed::max(Fixed &first, Fixed &second) {
	if (first >= second)
		return first;
	return second;
}

const Fixed   &Fixed::max(const Fixed &first, const Fixed &second) {
	if (first >= second)
		return first;
	return second;
}


/* ---------------------------------------------------------- UTILS FUNCTIONS */

int Fixed::getMaxNumber(int mem_size) {
	int max_number = 0;
	int i = 0;
	while (i < mem_size)
		max_number |= (1 << i++);
	return max_number;
}

int Fixed::getPower(void) {
	int max_number = getMaxNumber(_fract_size);
	int power = 1;
	while ((max_number / power) >= 10)
		power *= 10;
	return power;
}

int Fixed::getFixedFromParts(int integer_number, int fractional_part) {
	if (integer_number >= 0)
		return (((~(Fixed::getMaxNumber(Fixed::_fract_size + 1) << 23)
			& integer_number) << Fixed::_fract_size) | fractional_part);
	return ((((Fixed::getMaxNumber(Fixed::_fract_size + 1) << 23)
		| integer_number) << Fixed::_fract_size) | fractional_part);
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
