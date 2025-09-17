// Copyright 2025 Abdelkader Benajiba

#include <iostream>

std::string strToUpper(std::string str) {
  int i;

  i = -1;
  while (str[++i])
    str[i] = std::toupper(str[i]);
  return (str);
}

int main(int ac, char **av) {
  if (ac == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else {
    for (int i = 1; i < ac; i++)
      std::cout << strToUpper(av[i]);
    std::cout << std::endl;
  }
  return (0);
}
