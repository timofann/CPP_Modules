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

int main( void ) {

//    Fixed a;
    Fixed const b(1000000);
//    Fixed const c( 42.42f );
    Fixed const d(b);
//    100110001001011010000000
//    11110100001001000000
//    a = Fixed( 1234.4321f );

//    std::cout << "a is " << a << std::endl;
//    std::cout << "b is " << b << std::endl;
//    std::cout << "c is " << c << std::endl;
//    std::cout << "d is " << d << std::endl;
//    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
