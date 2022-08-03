/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:50:21 by dedelmir          #+#    #+#             */
/*   Updated: 2022/08/03 20:50:21 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.h"
#include <string>

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	printInfo(void);
	void	add(void);
	void	search(void);

private:
	size_t			id;
	size_t			records_cnt;
	Contact			records[8];
	static size_t	id_counter;
};

#endif
