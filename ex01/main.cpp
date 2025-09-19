// Copyright 2025 Abdelkader Benajiba

#include <iostream>
#include "PhoneBook.hpp"
#include "Colors.hpp"

int main() {
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
    if (cmd == "ADD") {
      if (book.addContact()) {
        std::cout << BOLD << GREEN
                  << "==== Contact added successfully at index "
                  << (book.getIndex() - 1) % MAX << " ===="
                  << RESET << std::endl;
      }
    } else if (cmd == "SEARCH") {
      book.searchContact();
    }
  } while (cmd != "EXIT");
  return 0;
}
