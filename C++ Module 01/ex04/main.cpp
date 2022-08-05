/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:48:16 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/04 22:48:17 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

bool	open_files(std::string infile, std::string outfile,
				   std::ifstream &fin, std::ofstream &fout) {
	fin.open(infile);
	if (!fin.is_open()) {
		std::cout << "Can't open file " << infile << std::endl;
		return 1;
	}
	fout.open(outfile);
	if (!fout.is_open()) {
		std::cout << "Can't open file " << outfile << std::endl;
		fin.close();
		return 1;
	}
	return 0;
}

void	replace_substring(std::ifstream &fin, std::ofstream &fout,
					      std::string substr1, std::string substr2) {
	size_t 	len = substr1.length();
	size_t	i = 1;
	char 	buff[len + 1];
	char 	ch;

	std::memset(buff, '\0', len + 1);
	buff[0] = substr1[0];
	while (i < len && fin.get(ch)) {
		buff[i++] = ch;
	}
	if (std::string(buff) == substr1) {
		fout << substr2;
	}
	else {
		fout << buff;
	}
}

void	generate_new_file(std::ifstream &fin, std::ofstream &fout,
						  std::string substr1, std::string substr2) {
	char	ch;

	while (fin.get(ch)) {
		if (ch != substr1[0]) {
			fout << ch;
		}
		else {
			replace_substring(fin, fout, substr1, substr2);
		}
	}
}

int	main(int argc, char **argv) {
	std::ofstream	fout;
	std::ifstream	fin;

	if (argc != 4) {
		std::cout << "Usage: ./SedIsForLosers <filename> <substr1> <substr2>"
				  << std::endl;
		return 0;
	}
	if (open_files(argv[1], std::string(argv[1]) + ".replace", fin, fout))
		return 0;

	generate_new_file(fin, fout, argv[2], argv[3]);

	fin.close();
	fout.close();
}
