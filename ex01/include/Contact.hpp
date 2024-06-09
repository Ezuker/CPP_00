/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:02:56 by bcarolle          #+#    #+#             */
/*   Updated: 2024/06/06 16:22:33 by bcarolle         ###   ########.fr       */
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
		Contact();
		~Contact();

		int			getIndex() const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getDarkestSecret() const;
		std::string	getPhoneNumber() const;
		static int	getNbContacts();

		void		setIndex(int value);
		void		setFirstName(std::string value);
		void		setLastName(std::string value);
		void		setNickName(std::string value);
		void		setDarkestSecret(std::string value);
		void		setPhoneNumber(std::string value);

	private:
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_darkestSecret;
		std::string	_phoneNumber;
};

#endif
