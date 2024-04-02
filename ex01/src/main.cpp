/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:52:39 by bcarolle          #+#    #+#             */
/*   Updated: 2024/04/02 10:35:40 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phoneBook;
	std::string	buffer;

	while (true)
	{
		std::cout << "Please, enter a command: ";
		getline(std::cin, buffer);
		if (std::cin.eof())
		{
			std::cout << "EOF detected, exit." << std::endl;
			return (1);
		}
		else
		{
			if (buffer == "ADD")
				phoneBook.add_contact();
			else if (buffer == "SEARCH")
			{
				if (!phoneBook.search_contact())
					return (1);
			}
			else if (buffer == "EXIT")
				return (0);
			else
				std::cout << "Wrong command: try using ADD, SEARCH or EXIT" << std::endl;
		}
	}
	return (0);
}
