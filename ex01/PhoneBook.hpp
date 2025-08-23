/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:41:56 by abenajib          #+#    #+#             */
/*   Updated: 2025/08/21 17:29:54 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
  public:
	PhoneBook();
	size_t getIndex();
	bool addContact();
	void searchContact();

  private:
	Contact contacts[8];
	std::size_t	index;
};

#endif // PHONEBOOK_HPP
