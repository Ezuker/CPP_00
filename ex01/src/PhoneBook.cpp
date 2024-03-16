/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:48:52 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/16 14:38:46 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_indexOldest = 1;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

static std::string	getInfo()
{
	std::string	buffer;
	std::string	tmp;

	std::cin >> buffer;
	while (std::cin.peek() != '\n')
	{
		buffer += " ";
		tmp = buffer;
		std::cin >> buffer;
		buffer = tmp + buffer;
	}
	return (buffer);
}

bool PhoneBook::add_contact(void)
{
	std::string buffer;

	if (PhoneBook::_indexOldest == 9)
		PhoneBook::_indexOldest = 1;
	PhoneBook::contact[PhoneBook::_indexOldest - 1].setIndex(PhoneBook::_indexOldest);
	std::cout << "Please, enter the first name: ";
	buffer = getInfo();
	PhoneBook::contact[PhoneBook::_indexOldest - 1].setFirstName(buffer);
	std::cout << "Please, enter the last name: ";
	buffer = getInfo();
	PhoneBook::contact[PhoneBook::_indexOldest - 1].setLastName(buffer);
	std::cout << "Please, enter the nick name: ";
	buffer = getInfo();
	PhoneBook::contact[PhoneBook::_indexOldest - 1].setNickName(buffer);
	std::cout << "Please, enter his darkest secret: ";
	buffer = getInfo();
	PhoneBook::contact[PhoneBook::_indexOldest - 1].setDarkestSecret(buffer);
	PhoneBook::_indexOldest++;
	return true;
}

bool PhoneBook::search_contact(std::string buffer)
{
	if (buffer == "SEARCH")
	{
		std::cout << "|  Index   |First Name|Last Name |Nick Name |His secret|" << std::endl;
		for (int i = 0; i < 8; i++)
		{
			std::cout << "|";
			std::cout << i + 1;
			std::cout << std::setw(10);
			std::cout << "|";
			std::cout << PhoneBook::contact[i].getFirstName().substr(0, 9);
			if (PhoneBook::contact[i].getFirstName().length() > 9)
				std::cout << ".";
			std::cout << std::setw(10 - PhoneBook::contact[i].getFirstName().length() + 1);
			std::cout << "|";
			std::cout << PhoneBook::contact[i].getLastName().substr(0, 9);
			if (PhoneBook::contact[i].getLastName().length() > 9)
				std::cout << ".";
			std::cout << std::setw(10 - PhoneBook::contact[i].getLastName().length() + 1);
			std::cout << "|";
			std::cout << PhoneBook::contact[i].getNickName().substr(0, 9);
			if (PhoneBook::contact[i].getNickName().length() > 9)
				std::cout << ".";
			std::cout << std::setw(10 - PhoneBook::contact[i].getNickName().length() + 1);
			std::cout << "|";
			std::cout << PhoneBook::contact[i].getDarkestSecret().substr(0, 9);
			if (PhoneBook::contact[i].getDarkestSecret().length() > 9)
				std::cout << ".";
			std::cout << std::setw(10 - PhoneBook::contact[i].getDarkestSecret().length() + 1);
			std::cout << "|";
			std::cout << std::endl;
		}
		return true;
	}
	else if (buffer.length() == 1 && buffer[0] >= '1' && buffer[0] <= '8')
	{
		int index = buffer[0] - '1';
		std::cout << "Information of the Contact" << std::endl;
		std::cout << "Index: " << PhoneBook::contact[index].getIndex() << std::endl;
		std::cout << "First Name: " << PhoneBook::contact[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << PhoneBook::contact[index].getLastName() << std::endl;
		std::cout << "Nick Name: " << PhoneBook::contact[index].getNickName() << std::endl;
	}
	else
		std::cout << "Invalid command" << std::endl;
	return false;
}
