/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:41:47 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/03 13:43:55 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"

class PhoneBook 
{
	public:
		Contact contact[8];

		bool add_contact();
		bool search_contact();
		void exit();

		PhoneBook();
		~PhoneBook();

	private:
		int	_indexOldest;
};

#endif
