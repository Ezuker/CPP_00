/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:52:39 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/04 02:47:20 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phoneBook;
	std::string	buffer;

	while (true)
	{
		std::cout << "Please, enter a command: ";
		std::cin >> buffer;
		if (std::cin.eof())
		{
			std::cout << "EOF detected, exit." << std::endl;
			break;
		}
		else
		{
			if (buffer == "ADD")
			{
				std::cin.ignore(256, '\n');
				phoneBook.add_contact();
			}
			else if (buffer == "SEARCH")
			{
				//If a user enter "SEARCH" command, the program should display the list of contacts
				//If a user enter "SEARCH 1" the program should display the full information of the contact
				if (std::cin.peek() != -1)
					std::cin >> buffer;
				phoneBook.search_contact(buffer);
			}
			else if (buffer == "EXIT")
			{
				return (0);
			}
			else
				std::cout << "Wrong command: try using ADD, SEARCH or EXIT" << std::endl;
		}
	}
	
}
