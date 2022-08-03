/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:52:43 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/03 20:52:43 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void) {
	std::string	stringSRC("HI THIS IS BRAIN");
	std::string	*stringPTR = &stringSRC;
	std::string	&stringREF = stringSRC;

	std::cout << "\033[3;37m--------- POINTERS ---------\033[0m" << std::endl;
	std::cout << "stringSRC: " << &stringSRC << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << "\033[3;37m---------- VALUES ----------\033[0m" << std::endl;
	std::cout << "stringSRC: " << stringSRC << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
}
