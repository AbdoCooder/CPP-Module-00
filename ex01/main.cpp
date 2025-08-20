/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:00:04 by abenajib          #+#    #+#             */
/*   Updated: 2025/08/20 19:26:37 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	book;
	std::string	cmd;

	do
	{
		std::cout << "Type a command (ADD / SEARCH / EXIT)" << std::endl;
		std::cin >> cmd;
		if (std::cin.eof())
			break;
		if (cmd.compare("ADD") == 0)
			book.addContact();
		// else if (cmd.compare("SEARCH") == 0)
		// 	book.searchContact();
	} while (cmd.compare("EXIT") != 0);
	return 0;
}
