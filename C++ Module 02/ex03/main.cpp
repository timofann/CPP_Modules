/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 06:13:02 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/13 22:57:02 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.h"
#include "Point.h"

int main(void) {

	Point a(0.0f, 0.0f);
	Point b(0.0f, 3.0f);
	Point c(4.0f, 3.0f);
	Point point(1.0f, 2.0f);

	if (bsp(a, b, c, point))
		std::cout << "Point is inside of triangle" <<std::endl;
	else
		std::cout << "Point is out of triangle" <<std::endl;

	return 0;
}
