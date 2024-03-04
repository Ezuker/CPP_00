/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:02:56 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/04 14:50:42 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>
# include <string>
# include <cstring>

class Contact
{
	public:
		int getIndex() const;
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getDarkestSecret() const;
		static int	getNbContacts();
		
		void setIndex(int value);
		void setFirstName(std::string value);
		void setLastName(std::string value);
		void setNickName(std::string value);
		void setDarkestSecret(std::string value);

		Contact();
		~Contact();

	private:
		int			_index;
		static int	_nbContacts;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_darkestSecret;
};

#endif
