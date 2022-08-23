/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:43:05 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/20 19:43:09 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {

protected:
	std::string type_;

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &copy);
	~WrongAnimal(void);
	WrongAnimal &operator=(const WrongAnimal &other);
	void        makeSound(void) const;
	std::string getType(void) const;
};

#endif
