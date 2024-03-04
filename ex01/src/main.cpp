/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:52:39 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/04 17:30:19 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	checker()
{
	if (std::cin.peek() != '\n')
		std::cout << "Too many args" << std::endl;
	else
		return (true);
	while (std::cin.peek() != '\n')
		std::cin.ignore();
	return (false);
}
int	main()
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
			return (1);
		}
		else
		{
			if (buffer == "ADD")
			{
				if (!checker())
					continue;
				phoneBook.add_contact();
			}
			else if (buffer == "SEARCH")
			{
				if (std::cin.peek() != '\n')
					std::cin >> buffer;
				if (!checker())
					continue;
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
	return (0);
}
