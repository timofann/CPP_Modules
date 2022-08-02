/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:38:02 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/26 16:38:04 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef std::string::const_iterator StrIter;

void	megaphone(std::string str) {
	for (StrIter it = str.begin(); it != str.end(); ++it) {
		std::cout << (char)std::toupper(*it);
	}
}

int main(int argc, char const *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		megaphone(std::string(argv[i]));
	}
	std::cout << std::endl;
	return (0);
}