// Copyright 2025 Abdelkader Benajiba

#ifndef EX01_PHONEBOOK_HPP_
#define EX01_PHONEBOOK_HPP_
#define MAX 8
#define COLS_WIDTH 10

#include "Contact.hpp"

class PhoneBook {
 public:
  PhoneBook();
  size_t getIndex() const;
  bool addContact();
  void searchContact();

 private:
  Contact contacts[MAX];
  std::size_t index;
};

#endif  // EX01_PHONEBOOK_HPP_
