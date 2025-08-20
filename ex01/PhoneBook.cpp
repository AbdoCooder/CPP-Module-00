/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:41:59 by abenajib          #+#    #+#             */
/*   Updated: 2025/08/20 19:27:05 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "PhoneBook constructed" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook destroyed" << std::endl;
}

void PhoneBook::addContact()
{
	if (this->index == 8)
		this->index = 0;

	std::string firstName;
	std::cout << "Type the first name" << std::endl;
	std::cin >> firstName;
	if (std::cin.eof() || firstName.empty())
	{
		std::cout << "Error: first name is required!" << std::endl;
		return ;
	}

	std::string lastName;
	std::cout << "Type the last name" << std::endl;
	std::cin >> lastName;
	if (std::cin.eof() || lastName.empty())
	{
		std::cout << "Error: last name is required!" << std::endl;
		return ;
	}

	std::string nickname;
	std::cout << "Type the nickname" << std::endl;
	std::cin >> nickname;
	if (std::cin.eof() || nickname.empty())
	{
		std::cout << "Error: nickname is required!" << std::endl;
		return ;
	}

	std::string phoneNumber;
	std::cout << "Type the phone number" << std::endl;
	std::cin >> phoneNumber;
	if (std::cin.eof() || phoneNumber.empty())
	{
		std::cout << "Error: phone number is required!" << std::endl;
		return ;
	}

	std::string darkestSecret;
	std::cout << "Write the darkest secret" << std::endl;
	std::cin >> darkestSecret;
	if (std::cin.eof() || darkestSecret.empty())
	{
		std::cout << "Error: darkest secret is required!" << std::endl;
		return ;
	}

	this->contacts[index].fillContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	this->index++;
}
