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
        this->_value = (~(511 << 23) & integer_number) << 8;
    else
        this->_value = (((511 << 23) | integer_number) << 8);
//    printBits(this->_value);
}

Fixed::Fixed(const float floating_point) {
    std::cout << "\033[3;37m"
              << "Fixed floating-point constructor called"
              << "\033[0m" << std::endl;
//    printBits(*((int *)(&floating_point)));

    int integer_number = roundf(floating_point);
    int fractional_part = roundf((floating_point - integer_number) * 100)
            * ((integer_number >= 0) * 2 - 1);
    int sign = integer_number >> 31;
    if (!sign)
        this->_value
            = ((~(511 << 23) & integer_number) << 8) | fractional_part;
    else
        this->_value
            = (((511 << 23) | integer_number) << 8) | fractional_part;
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
    integer_number = this->_value >> 8;
    return (integer_number);
}

float   Fixed::toFloat(void) const {
    float   floating_number;
    int fractional_part = this->_value & (255);
    int integer_number = this->_value >> 8;
    int sign = integer_number >> 31;
    if (!sign)
        floating_number = integer_number + (float)fractional_part / 100;
    else
        floating_number = integer_number - (float)fractional_part / 100;
    return (floating_number);
}

void Fixed::printBits(const int bits) {
    std::cout << "\033[37m";
    for (int i = 31; i >= 0; --i) {
        std::cout << ((bits >> i) & 1);
    }
    std::cout << "\033[0m" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Fixed &output) {
    int fractional_part = output.getRawBits() & (255);
    int integer_number = output.getRawBits() >> 8;
	if (fractional_part % 10)
        return os << integer_number << "." << fractional_part;
	return os << integer_number << ".0" << fractional_part;
}
