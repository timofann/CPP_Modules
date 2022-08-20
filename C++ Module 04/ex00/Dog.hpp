/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:38:59 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/20 17:39:00 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"

class Dog : public Animal {
protected:
	std::string type_;
public:
	Dog();
	Dog(const Dog &copy);
	~Dog();
	Dog         &operator=(const Dog &other);
	void        makeSound(void) const;
	std::string getType(void) const;
};

#endif
