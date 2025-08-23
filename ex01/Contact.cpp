/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:55:38 by abenajib          #+#    #+#             */
/*   Updated: 2025/08/23 16:40:28 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::fillContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

static std::string formatString_10Width(const std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

void Contact::displayContactInfo()
{
	std::cout << std::setw(10) << formatString_10Width(firstName) << '|';
	std::cout << std::setw(10) << formatString_10Width(lastName) << '|';
	std::cout << std::setw(10) << formatString_10Width(nickname) << '|' << std::endl;
}
