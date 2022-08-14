/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:30:48 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/14 12:30:50 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.h"
#include "Fixed.h"

Fixed triangle_sqr(const Point &a, const Point &b, const Point &c) {
	std::cout << "\033[3;33mtriangle_sqr start\033[0m" << std::endl;
	Fixed sqr = (((a.x() - c.y()) * (b.y() - a.y())) -
	             ((b.y() - a.y()) * (a.x() - c.x())));
	std::cout << "\033[3;33mtriangle_sqr end\033[0m" << std::endl;
	return sqr;
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	std::cout << "\033[3;33mbsp start\033[0m" << std::endl;
	Fixed   sqr1 = triangle_sqr(a, b, point);
	Fixed   sqr2 = triangle_sqr(b, c, point);
	Fixed   sqr3 = triangle_sqr(c, a, point);

	std::cout << "\033[3;33mbsp end\033[0m" << std::endl;
	if (sqr1.isPositive() && sqr2.isPositive() && sqr3.isPositive())
		return true;
	if (sqr1.isNegative() && sqr2.isNegative() && sqr3.isNegative())
		return true;
	return false;
}
