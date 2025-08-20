/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:41:56 by abenajib          #+#    #+#             */
/*   Updated: 2025/08/20 18:36:41 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
  public:
	PhoneBook();
	void addContact();
	~PhoneBook();

  private:
	Contact contacts[8];
	std::int8_t	index;
};

#endif // PHONEBOOK_HPP
