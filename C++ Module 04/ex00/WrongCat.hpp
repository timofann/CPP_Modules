/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:43:17 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/20 19:43:19 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
protected:
	std::string type_;
public:
	WrongCat(void);
	WrongCat(const WrongCat &copy);
	~WrongCat(void);
	WrongCat    &operator=(const WrongCat &other);
	void        makeSound(void) const;
	std::string getType(void) const;
};

#endif
