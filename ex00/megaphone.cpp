/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:26:42 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/30 00:25:48 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main (int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string string = argv[i];
		for (size_t j = 0; j < string.length(); j++)
		{
			argv[i][j] = toupper(argv[i][j]);
			std::cout << argv[i][j];
		}
	}
	std::cout << std::endl;
	return (0);
}
