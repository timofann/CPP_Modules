/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:38:59 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/21 18:57:08 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

private:
	Brain       *brain_;

protected:
	std::string type_;

public:
	Dog(void);
	Dog(const Dog &copy);
	~Dog(void);
	Dog         &operator=(const Dog &other);
	void        makeSound(void) const;
	std::string getType(void) const;
	void        printIdeas(void);
	void        addIdea(const std::string &idea);
};

#endif
