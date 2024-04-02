/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:48:52 by bcarolle          #+#    #+#             */
/*   Updated: 2024/04/02 10:38:43 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_indexOldest = 1;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

static std::string	getInfo(std::string msg)
{
	std::string	buffer;

	while (buffer.length() == 0)
	{
		std::cout << msg;
		getline(std::cin, buffer);
		if (std::cin.eof())
		{
			std::cout << "EOF detected, exit." << std::endl;
			return ("");
		}
	}
	return (buffer);
}

Contact *PhoneBook::getContact()
{
	return (this->_contact);
}

bool PhoneBook::add_contact()
{
	std::string buffer;

	if (this->_indexOldest == 9)
		this->_indexOldest = 1;
	this->getContact()[this->_indexOldest - 1].setIndex(this->_indexOldest);
	buffer = getInfo("Please, enter the first name: ");
	if (buffer == "")
		return false;
	this->getContact()[this->_indexOldest - 1].setFirstName(buffer);
	buffer = getInfo("Please, enter the last name: ");
	if (buffer == "")
		return false;
	this->getContact()[this->_indexOldest - 1].setLastName(buffer);
	buffer = getInfo("Please, enter the nick name:");
	if (buffer == "")
		return false;
	this->getContact()[this->_indexOldest - 1].setNickName(buffer);
	buffer = getInfo("Please, enter his darkest secret:");
	if (buffer == "")
		return false;
	this->getContact()[this->_indexOldest - 1].setDarkestSecret(buffer);
	this->_indexOldest++;
	return true;
}

void	PhoneBook::display_contact()
{
	std::cout << "|  Index   |First Name|Last Name |Nick Name |His secret|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|";
		std::cout.width(10);
		std::cout << std::right << i + 1;
		std::cout << "|";
		if (this->getContact()[i].getFirstName().length() > 10)
		{
			std::cout.width(9);
			std::cout << std::right << this->getContact()[i].getFirstName().substr(0, 9);
			std::cout << ".";
		}
		else
		{
			std::cout.width(10);
			std::cout << std::right << this->getContact()[i].getFirstName();
		}
		std::cout << "|";
		if (this->getContact()[i].getLastName().length() > 10)
		{
			std::cout.width(9);
			std::cout << std::right << this->getContact()[i].getLastName().substr(0, 9);
			std::cout << ".";
		}
		else
		{
			std::cout.width(10);
			std::cout << std::right << this->getContact()[i].getLastName();
		}
		std::cout << "|";
		if (this->getContact()[i].getNickName().length() > 10)
		{
			std::cout.width(9);
			std::cout << std::right << this->getContact()[i].getNickName().substr(0, 9);
			std::cout << ".";
		}
		else
		{
			std::cout.width(10);
			std::cout << std::right << this->getContact()[i].getNickName();
		}
		std::cout << "|";
		if (this->getContact()[i].getDarkestSecret().length() > 10)
		{
			std::cout.width(9);
			std::cout << std::right << this->getContact()[i].getDarkestSecret().substr(0, 9);
			std::cout << ".";
		}
		else
		{
			std::cout.width(10);
			std::cout << std::right << this->getContact()[i].getDarkestSecret();
		}
		std::cout << "|";
		std::cout << std::endl;
	}
}

bool PhoneBook::search_contact()
{
	std::string	buffer;
	int			index;

	this->display_contact();
	std::cout << "Please, enter the index of the contact you want to see: ";
	while (1)
	{
		getline(std::cin, buffer);
		if (std::cin.eof())
		{
			std::cout << "EOF detected, exit." << std::endl;
			return (false);
		}
		if (buffer.length() == 1)
		{
			index = buffer[0] - 48;
			if (index < 1 || index > 8)
				std::cout << "Index out of range." << std::endl;
			else
				break;
		}
	}
	std::cout << "Information of the Contact" << std::endl;
	std::cout << "Index: " << this->getContact()[index - 1].getIndex() << std::endl;
	std::cout << "First Name: " << this->getContact()[index - 1].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->getContact()[index - 1].getLastName() << std::endl;
	std::cout << "Nick Name: " << this->getContact()[index - 1].getNickName() << std::endl;
	return (true);
}
