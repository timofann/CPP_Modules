/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:52:11 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/13 22:57:48 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <ostream>

class Fixed {

private:
    static const int    _fract_size;
    int                 _value;
	void                printBits(const int bits) const;
	int                 getFixedFromParts(int integer_number, int fractional_part);

public:
    Fixed(void);
    Fixed(const Fixed &copy);
    Fixed(const int integer_number);
    Fixed(const float floating_point);
	Fixed(const int integer_part, const int fractional_part);
    ~Fixed(void);

    Fixed               &operator=(const Fixed &assign);
	bool                operator<(const Fixed &right) const;
	bool                operator>(const Fixed &right) const;
	bool                operator==(const Fixed &right) const;
	bool                operator!=(const Fixed &right) const;
	bool                operator>=(const Fixed &right) const;
	bool                operator<=(const Fixed &right) const;
	Fixed               operator+(const Fixed &second_component) const;
	Fixed               operator-(const Fixed &second_component) const;
	Fixed               operator*(const Fixed &second_component) const;
	Fixed               operator/(const Fixed &second_component) const;
	const Fixed         operator++(int);
	Fixed               &operator++(void);
	const Fixed         operator--(int);
	Fixed               &operator--(void);
	int                 getRawBits(void) const;
	void                setRawBits(int const raw);
    int                 toInt(void) const;
    float               toFloat(void) const;
	static Fixed        &min(Fixed &first, Fixed &second);
	static const Fixed  &min(const Fixed &first, const Fixed &second);
	static Fixed        &max(Fixed &first, Fixed &second);
	static const Fixed  &max(const Fixed &first, const Fixed &second);
	static int          getFractSize(void);
	static int          getMaxNumber(int mem_size);
	static int          getPower(void);
};

std::ostream&   operator<<(std::ostream &os, const Fixed &output);

#endif
