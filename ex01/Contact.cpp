/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:55:38 by abenajib          #+#    #+#             */
/*   Updated: 2025/08/20 19:46:03 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include "Contact.hpp"

Contact::Contact() {
	std::cout << "Contact constructed" << std::endl;
}

Contact::~Contact() {
	std::cout << "Contact destroyed" << std::endl;
}

void Contact::fillContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
	// this.setFirstName(firstName);
}
