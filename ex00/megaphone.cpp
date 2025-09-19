// Copyright 2025 Abdelkader Benajiba

#include <iostream>
#include <string>

std::string strToUpper(std::string str) {
  int idx = -1;

  while (str[++idx] != 0) {
    str[idx] = static_cast<char>(std::toupper(str[idx]));
  }
  return (str);
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else {
    std::string av_str;
    for (int idx = 1; idx < argc; idx++) {
      std::cout << strToUpper(argv[idx]);
    }
    std::cout << std::endl;
  }
  return (0);
}
