// Copyright 2025 Abdelkader Benajiba

#include <iomanip>
#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Colors.hpp"

PhoneBook::PhoneBook() : index(0) {}

size_t PhoneBook::getIndex() const { return (index); }

bool PhoneBook::addContact() {
  std::string firstName;
  std::cout << CYAN << "    ==== Type the " << BOLD << "first name" << RESET
            << CYAN << " : " << RESET;
  std::getline(std::cin, firstName);
  if (firstName.empty()) {
    std::cin.clear();
    std::cout << "    ==== Error: first name is required!" << std::endl;
    return (false);
  }

  std::string lastName;
  std::cout << CYAN << "    ==== Type the " << BOLD << "last name" << RESET
            << CYAN << " : " << RESET;
  std::getline(std::cin, lastName);
  if (lastName.empty()) {
    std::cin.clear();
    std::cout << "    ==== Error: last name is required!" << std::endl;
    return (false);
  }

  std::string nickname;
  std::cout << CYAN << "    ==== Type the " << BOLD << "nickname" << RESET
            << CYAN << " : " << RESET;
  std::getline(std::cin, nickname);
  if (nickname.empty()) {
    std::cin.clear();
    std::cout << "    ==== Error: nickname is required!" << std::endl;
    return (false);
  }

  std::string phoneNumber;
  std::cout << CYAN << "    ==== Type the " << BOLD << "phone number" << RESET
            << CYAN << " : " << RESET;
  std::getline(std::cin, phoneNumber);
  if (phoneNumber.empty()) {
    std::cin.clear();
    std::cout << "    ==== Error: phone number is required!" << std::endl;
    return (false);
  }

  std::string darkestSecret;
  std::cout << CYAN << "    ==== Write the " << BOLD << "darkest secret"
            << RESET << CYAN << " : " << RESET;
  std::getline(std::cin, darkestSecret);
  if (darkestSecret.empty()) {
    std::cin.clear();
    std::cout << "    ==== Error: darkest secret is required!" << std::endl;
    return (false);
  }

  std::size_t target = index % MAX;
  this->contacts[target].fillContact(firstName, lastName, nickname, phoneNumber,
                                     darkestSecret);
  this->index++;
  return (true);
}

static int getUserIndex() {
  std::string userIndex;
  std::cout << MAGENTA
            << "    ==== Please select an index to search for: " << RESET;
  std::getline(std::cin, userIndex);
  if (userIndex.empty()) {
    std::cout << "    ==== Choosing an index is required !" << std::endl;
    return (-1);
  }
  if (userIndex.length() != 1 ||
      std::isdigit(static_cast<unsigned char>(userIndex[0])) != 1) {
    std::cout << BOLD << RED
              << "    ==== Invalid index! Please type a single digit (0-7)."
              << RESET << std::endl;
    return (-1);
  }
  int idx = userIndex[0] - '0';
  if (idx < 0 || idx > MAX - 1) {
    std::cout << "    ==== Invalid index! Please type a single digit (0-7)."
              << std::endl;
    return (-1);
  }
  return (idx);
}

void PhoneBook::searchContact() {
  if (index == 0) {
    std::cout << YELLOW << "    ==== The PhoneBook is Empty! Please " << GREEN
              << "ADD" << YELLOW << " Contacts :)" << RESET << std::endl;
    return;
  }

  std::cout << BOLD << UNDERLINE
            << "\n     index|first name| last name|  nickname|" << RESET
            << std::endl;
  for (size_t i = 0; i < MAX; i++) {
    if (i < index) {
      std::cout << std::setw(COLS_WIDTH) << i << '|';
      this->contacts[i].displayContactInfoFormat();
    }
  }

  int idx = getUserIndex();
  if (idx == -1) {
    return;
  }
  if ((std::size_t)idx > index - 1) {
    std::cout << BOLD << RED
              << "    ==== No Contact found in this index ):" << RESET
              << std::endl;
    return;
  }

  this->contacts[idx].displayContactInfo(idx);
  std::cout << std::endl;
}
