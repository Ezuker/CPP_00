/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:48:52 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/04 02:44:16 by bcarolle         ###   ########.fr       */
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
	std::string buffer;

	if (PhoneBook::_indexOldest == 8)
		PhoneBook::_indexOldest = 0;
	PhoneBook::contact[PhoneBook::_indexOldest].setIndex(PhoneBook::_indexOldest);
	std::cout << "Please, enter the first name: ";
	std::cin >> buffer;
	PhoneBook::contact[PhoneBook::_indexOldest].setFirstName(buffer);
	std::cout << "Please, enter the last name: ";
	std::cin >> buffer;
	PhoneBook::contact[PhoneBook::_indexOldest].setLastName(buffer);
	std::cout << "Please, enter the nick name: ";
	std::cin >> buffer;
	PhoneBook::contact[PhoneBook::_indexOldest].setNickName(buffer);
	PhoneBook::_indexOldest++;
	return true;
}

bool PhoneBook::search_contact(std::string buffer)
{
	if (buffer == "SEARCH")
	{
		std::cout << "|  Index   |First Name|Last Name |Nick Name |" << std::endl;
		for (int i = 0; i < 8; i++)
		{
			std::cout << "|";
			std::cout << std::setw(10);
			std::cout << PhoneBook::contact[i].getIndex() + 1;
			std::cout << "|";
			std::cout << std::setw(10);
			std::cout << PhoneBook::contact[i].getFirstName();
			std::cout << "|";
			std::cout << std::setw(10);
			std::cout << PhoneBook::contact[i].getLastName();
			std::cout << "|";
			std::cout << std::setw(10);
			std::cout << PhoneBook::contact[i].getNickName();
			std::cout << "|";
			std::cout << std::endl;
		}
		return true;
	}
	else if (buffer.length() == 1 && isdigit(buffer[0]) && buffer[0] < '9')
	{
		std::cout << "Information of the" << PhoneBook::contact[0].getIndex() << std::endl;
	}
	return false;
}
