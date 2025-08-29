/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:55:36 by abenajib          #+#    #+#             */
/*   Updated: 2025/08/29 19:41:32 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
  public:
	void fillContact(std::string firstName, std::string lastName,
					 std::string nickname, std::string phoneNumber,
					 std::string darkestSecret);
	void displayContactInfoFormat();
	void displayContactInfo(int idx);

  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif // CONTACT_HPP
