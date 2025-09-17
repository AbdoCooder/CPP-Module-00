// Copyright 2025 Abdelkader Benajiba

#include <iostream>
#include "PhoneBook.hpp"
#include "Colors.hpp"

int main(void) {
  PhoneBook   book;
  std::string cmd;

  do {
    std::cout << BOLD << CYAN << "==== Type a command (" << GREEN << "ADD"
              << CYAN << " / " << YELLOW << "SEARCH" << CYAN << " / " << RED
              << "EXIT" << CYAN << ") ====" << RESET << std::endl;
    std::getline(std::cin, cmd);
    if (std::cin.eof()) {
      std::cout << BOLD << RED << "EOF" << RESET << std::endl;
      break;
    }
    if (cmd.compare("ADD") == 0) {
      if (book.addContact()) {
        std::cout << BOLD << GREEN
                  << "==== Contact added successfully at index "
                  << (book.getIndex() - 1) % 8 << " ===="
                  << RESET << std::endl;
      }
    } else if (cmd.compare("SEARCH") == 0) {
      book.searchContact();
    }
  } while (cmd.compare("EXIT") != 0);
  return 0;
}
