// Copyright 2025 Abdelkader Benajiba

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"
#include "Colors.hpp"

void Contact::fillContact(std::string firstName, std::string lastName,
  std::string nickname, std::string phoneNumber, std::string darkestSecret) {
  this->firstName = firstName;
  this->lastName = lastName;
  this->nickname = nickname;
  this->phoneNumber = phoneNumber;
  this->darkestSecret = darkestSecret;
}

static std::string formatString_10Width(const std::string str) {
  if (str.length() > 10)
    return (str.substr(0, 9) + '.');
  return (str);
}

void Contact::displayContactInfoFormat() {
  std::cout << std::setw(10) << formatString_10Width(firstName) << '|';
  std::cout << std::setw(10) << formatString_10Width(lastName) << '|';
  std::cout << std::setw(10) << formatString_10Width(nickname) << '|'
            << std::endl;
}

void Contact::displayContactInfo(int idx) {
  std::cout << "\n========FULL CONTACT INFORMATION========\n";
  std::cout << "    index          : ";
  std::cout << idx << std::endl;
  std::cout << "    firstName      : ";
  std::cout << firstName << std::endl;
  std::cout << "    lastName       : ";
  std::cout << lastName << std::endl;
  std::cout << "    nickname       : ";
  std::cout << nickname << std::endl;
  std::cout << "    phoneNumber    : ";
  std::cout << phoneNumber << std::endl;
  std::cout << "    darkestSecret  : ";
  std::cout << darkestSecret << std::endl;
}
