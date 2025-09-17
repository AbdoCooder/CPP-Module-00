// Copyright 2025 Abdelkader Benajiba

#ifndef EX01_PHONEBOOK_HPP_
#define EX01_PHONEBOOK_HPP_

#include "Contact.hpp"

class PhoneBook {
 public:
  PhoneBook();
  size_t getIndex();
  bool addContact();
  void searchContact();

 private:
  Contact     contacts[8];
  std::size_t index;
};

#endif  // EX01_PHONEBOOK_HPP_
