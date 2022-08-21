/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:07:28 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/21 18:56:52 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define MAX_IDEAS_COUNT 100

class Brain {
private:
	std::string ideas_[MAX_IDEAS_COUNT];
	int         ideas_num_;
public:
	Brain();
	Brain(const Brain &copy);
	~Brain();
	Brain       &operator=(const Brain &other);
	void        addIdea(std::string idea);
	std::string getIdea(int i);
	int         getIdeasNum(void);
	void        setIdeasNum(int num);
};

#endif
