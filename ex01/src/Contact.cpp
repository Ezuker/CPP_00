/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:03:47 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/03 16:23:19 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	setIndex(0);
	setFirstName("");
	setLastName("");
	setNickName("");
	return;
}

Contact::~Contact(void)
{
	return;
}

int Contact::getIndex() const
{
	return (this->_index);
}

std::string Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string Contact::getLastName() const
{
	return (this->_lastName);
}

std::string Contact::getNickName() const
{
	return (this->_nickName);
}

void Contact::setIndex(int value)
{
	this->_index = value;
}

void Contact::setFirstName(std::string value)
{
	this->_firstName = value;
}

void Contact::setLastName(std::string value)
{
	this->_lastName = value;
}

void Contact::setNickName(std::string value)
{
	this->_nickName = value;
}
