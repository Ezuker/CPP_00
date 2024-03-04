/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:52:39 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/04 02:55:59 by bcarolle         ###   ########.fr       */
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
				phoneBook.add_contact();
			}
			else if (buffer == "SEARCH")
			{
				if (std::cin.peek() != '\n')
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
