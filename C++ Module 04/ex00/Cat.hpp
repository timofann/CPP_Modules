/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:38:59 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/20 17:39:00 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal {
protected:
	std::string type_;
public:
	Cat();
	Cat(const Cat &copy);
	~Cat();
	Cat         &operator=(const Cat &other);
	void        makeSound(void) const;
	std::string getType(void) const;
};

#endif
