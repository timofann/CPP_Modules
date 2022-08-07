#include "Fixed.h"
#include <iostream>

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

int Fixed::getRawBits(void) const {
    std::cout << "\033[3;37m"
              << "getRawBits member function called"
              << "\033[0m" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(const int raw) {
    std::cout << "\033[3;37m"
              << "setRawBits member function called"
              << "\033[0m" << std::endl;
    this->_value = raw;
}

