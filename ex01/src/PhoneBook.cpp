/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:48:52 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/03 18:43:05 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_indexOldest = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

bool PhoneBook::add_contact(void)
{
	return true;
}

bool PhoneBook::search_contact(std::string buffer)
{
	std::cout << "|Index     |First Name|Last Name |Nick Name|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|";
		std::cout << PhoneBook::contact[i].getIndex();
		std::cout << "|";
	}
	return true;
}

void PhoneBook::exit(void)
{
	return;
}
