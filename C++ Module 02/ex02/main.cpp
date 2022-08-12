/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 06:13:02 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/07 06:13:45 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.h"

int
main(void) {

	Fixed a;
	Fixed const b( 200.99f );
	Fixed const c( 100.1f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	a = b - c + d;

	std::cout << "a is " << a << std::endl;
//	std::cout << "b is " << b << std::endl;
//	std::cout << "c is " << c << std::endl;
//	std::cout << "d is " << d << std::endl;
//	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
//	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
//	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
//	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
//	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
//	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
//	std::cout << "d is " << d.toFloat() << " as float" << std::endl;

	return 0;
}
