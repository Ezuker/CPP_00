/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:26:42 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/02 18:34:55 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	ft_strlen(char *string)
{
	int i = 0;
	while (string[i])
		i++;
	return (i);
}

int main (int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; j < ft_strlen(argv[i]); j++)
		{
			argv[i][j] = to_upper(argv[i][j]);
			std::cout << argv[i][j];
		}
	}
	std::cout << std::endl;
	return (0);
}
