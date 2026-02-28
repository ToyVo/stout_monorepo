//
// Created by Collin Diekvoss on 3/4/20.
//

#include <fstream>
#include <iostream>
#include <string>

void write_history(const std::string &cmd) {
  std::ofstream historyFile(".shellhistory", std::ios_base::app);
  historyFile << cmd << std::endl;
}

void read_history() {
  std::ifstream historyFile(".shellhistory");
  std::string cmd;
  while (std::getline(historyFile, cmd)) {
    std::cout << cmd << std::endl;
  }
}
