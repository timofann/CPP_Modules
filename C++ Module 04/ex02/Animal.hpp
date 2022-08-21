/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:10:09 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/21 20:12:12 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
protected:
	std::string type_;
public:
	Animal();
	Animal(const Animal &copy);
	virtual        ~Animal();
	Animal          &operator=(const Animal &other);
	virtual void    makeSound(void) const = 0;
	std::string     getType(void) const;
};

#endif