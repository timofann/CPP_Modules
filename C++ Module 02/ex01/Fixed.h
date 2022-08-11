/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:52:11 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/07 06:13:48 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <ostream>

class Fixed {

private:
    static const int    _fract_size;
    int                 _value;

public:
    Fixed(void);
    Fixed(const Fixed &copy);
    Fixed(const int integer_number);
    Fixed(const float floating_point);
    ~Fixed(void);
    Fixed   &operator=(const Fixed &assign);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    int     toInt(void) const;
    float   toFloat(void) const;
    void    printBits(const int bits);
};

std::ostream&   operator<<(std::ostream &os, const Fixed &output);

#endif
