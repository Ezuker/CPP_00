/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:48:52 by bcarolle          #+#    #+#             */
/*   Updated: 2024/06/09 17:12:47 by bcarolle         ###   ########.fr       */
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
	buffer = getInfo("Please, enter the nick name: ");
	if (buffer == "")
		return false;
	this->getContact()[this->_indexOldest - 1].setNickName(buffer);
	buffer = getInfo("Please, enter his phone number: ");
	if (buffer == "")
		return false;
	this->getContact()[this->_indexOldest - 1].setPhoneNumber(buffer);
	buffer = getInfo("Please, enter his darkest secret: ");
	if (buffer == "")
		return false;
	this->getContact()[this->_indexOldest - 1].setDarkestSecret(buffer);
	this->_indexOldest++;
	return true;
}

static	void display_info(std::string name)
{
	if (name.length() > 10)
	{
		std::cout.width(9);
		std::cout << std::right << name.substr(0, 9);
		std::cout << ".";
	}
	else
	{
		std::cout.width(10);
		std::cout << std::right << name;
	}
	std::cout << "|";
}

void	PhoneBook::display_contact()
{
	std::cout << "|     Index|First Name| Last Name| Nick Name|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|";
		std::cout.width(10);
		std::cout << std::right << i + 1;
		std::cout << "|";
		display_info(this->getContact()[i].getFirstName());
		display_info(this->getContact()[i].getLastName());
		display_info(this->getContact()[i].getNickName());
		std::cout << std::endl;
	}
}

bool PhoneBook::search_contact()
{
	std::string	buffer;
	int			index;

	this->display_contact();
	while (1)
	{
		std::cout << "Please, enter the index of the contact you want to see: ";
		getline(std::cin, buffer);
		if (std::cin.eof())
		{
			std::cout << "EOF detected, exit." << std::endl;
			return (false);
		}
		if (buffer.length() == 1 && std::isdigit(buffer[0]))
		{
			index = buffer[0] - 48;
			if (index < 1 || index > 8)
				std::cout << "Index out of range." << std::endl;
			else
				break;
		}
		else
			std::cout << "Wrong index." << std::endl;
	}
	std::cout << "Information of the Contact" << std::endl;
	std::cout << "Index: " << index << std::endl;
	std::cout << "First Name: " << this->getContact()[index - 1].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->getContact()[index - 1].getLastName() << std::endl;
	std::cout << "Nick Name: " << this->getContact()[index - 1].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->getContact()[index - 1].getPhoneNumber() << std::endl;
	std::cout << "His Darkest Secret: " << this->getContact()[index - 1].getDarkestSecret() << std::endl;
	return (true);
}
