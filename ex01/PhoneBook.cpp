// Copyright 2025 Abdelkader Benajiba

#include "PhoneBook.hpp"
#include "Colors.hpp"

#include <iomanip>  // for std::setw
#include <iostream> // for std::cout, std::endl
#include <stdlib.h> // for atoi
#include <string>   // for std::string, std::getline

PhoneBook::PhoneBook() : index(0) {}

size_t PhoneBook::getIndex() const { return (index); }

bool PhoneBook::addContact() {
  std::string firstName;
  std::cout << CYAN << "    ==== Type the " << BOLD << "first name" << RESET
            << CYAN << " : " << RESET;
  std::getline(std::cin, firstName);
  if (firstName.empty()) {
    std::cin.clear();
    std::cout << RED << "    ==== Error: first name is required!" << RESET << std::endl;
    return (false);
  }
  if (firstName.find('\t') != std::string::npos) {
    std::cin.clear();
    std::cout << RED << "    ==== Error: first name cannot contain tab characters!"
              << RESET << std::endl;
    return (false);
  }

  std::string lastName;
  std::cout << CYAN << "    ==== Type the " << BOLD << "last name" << RESET
            << CYAN << " : " << RESET;
  std::getline(std::cin, lastName);
  if (lastName.empty()) {
    std::cin.clear();
    std::cout << RED << "    ==== Error: last name is required!" << RESET << std::endl;
    return (false);
  }
  if (lastName.find('\t') != std::string::npos) {
    std::cin.clear();
    std::cout << RED << "    ==== Error: last name cannot contain tab characters!"
              << RESET << std::endl;
    return (false);
  }

  std::string nickname;
  std::cout << CYAN << "    ==== Type the " << BOLD << "nickname" << RESET
            << CYAN << " : " << RESET;
  std::getline(std::cin, nickname);
  if (nickname.empty()) {
    std::cin.clear();
    std::cout << RED << "    ==== Error: nickname is required!" << RESET << std::endl;
    return (false);
  }
  if (nickname.find('\t') != std::string::npos) {
    std::cin.clear();
    std::cout << RED << "    ==== Error: nickname cannot contain tab characters!"
              << RESET << std::endl;
    return (false);
  }

  std::string phoneNumber;
  std::cout << CYAN << "    ==== Type the " << BOLD << "phone number" << RESET
            << CYAN << " : " << RESET;
  std::getline(std::cin, phoneNumber);
  if (phoneNumber.empty()) {
    std::cin.clear();
    std::cout << RED << "    ==== Error: phone number is required!" << RESET << std::endl;
    return (false);
  }
  if (phoneNumber.find('\t') != std::string::npos) {
    std::cin.clear();
    std::cout << RED << "    ==== Error: phone number cannot contain tab characters!"
              << RESET << std::endl;
    return (false);
  }

  std::string darkestSecret;
  std::cout << CYAN << "    ==== Write the " << BOLD << "darkest secret"
            << RESET << CYAN << " : " << RESET;
  std::getline(std::cin, darkestSecret);
  if (darkestSecret.empty()) {
    std::cin.clear();
    std::cout << RED << "    ==== Error: darkest secret is required!"
              << RESET << std::endl;
    return (false);
  }
  if (darkestSecret.find('\t') != std::string::npos) {
    std::cin.clear();
    std::cout << RED << "    ==== Error: darkest secret cannot contain tab characters!"
              << RESET << std::endl;
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
  std::cout << MAGENTA << "    ==== Please select an index to search for: " << RESET;
  std::getline(std::cin, userIndex);
  if (userIndex.empty()) {
    std::cout << "    ==== Choosing an index is required !" << std::endl;
    return (-1);
  }
  int idx = std::atoi(userIndex.c_str());
  if (userIndex.find_last_not_of("0123456789") != std::string::npos || idx < 0 || idx > MAX - 1) {
    std::cout << "    ==== Invalid index! Please type a single digit (1-7)."
              << std::endl;
    return (-1);
  }
  return (idx);
}

void PhoneBook::searchContact() {
  if (index <= 0) {
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
