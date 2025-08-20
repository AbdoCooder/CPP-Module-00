/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:55:36 by abenajib          #+#    #+#             */
/*   Updated: 2025/08/20 18:57:59 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
  public:
	Contact();
	void fillContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);
	~Contact();

  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif // CONTACT_HPP
