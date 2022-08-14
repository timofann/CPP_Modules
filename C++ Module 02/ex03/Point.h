/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:31:01 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/14 12:31:01 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {

private:
	const Fixed _x;
	const Fixed _y;

public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &copy);
	~Point(void);
	Point   &operator=(const Point &assign);
	const Fixed x(void) const;
	const Fixed y(void) const;
};

bool bsp(const Point a, const Point b, const Point c, const Point p);

#endif
