// Copyright 2025 Abdelkader Benajiba

#ifndef EX01_CONTACT_HPP_
#define EX01_CONTACT_HPP_

#include <string>

class Contact {
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

#endif  // EX01_CONTACT_HPP_
