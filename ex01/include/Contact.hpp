/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:02:56 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/03 13:43:09 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
	public:
		int getIndex() const;
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;

		void setIndex(int value);
		void setFirstName(std::string value);
		void setLastName(std::string value);
		void setNickName(std::string value);

		Contact();
		~Contact();

	private:
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
};

#endif
