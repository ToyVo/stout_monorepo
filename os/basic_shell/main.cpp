//
// Created by Collin Diekvoss on 3/4/20.
//

#include "cmd.hpp"
#include "history.hpp"
#include "util.hpp"
#include <iostream>
#include <string>

int main() {
  std::string input_cmd;
  std::string cmd1;
  std::string cmd2;

  while (true) {
    std::cout << getenv("USER") << " > ";
    std::getline(std::cin, input_cmd);
    write_history(input_cmd);
    if (input_cmd == "exit") {
      return EXIT_SUCCESS;
    } else if (input_cmd == "history") {
      read_history();
    } else if (input_cmd == "pwd") {
      std::cout << getenv("PWD") << std::endl;
    } else {
      switch (eval_cmd(input_cmd, cmd1, cmd2)) {
      case PIPE:
        pipe_cmd(cmd1, cmd2);
        break;
      case REDIRECT_IN:
        redirect_in_cmd(cmd1, cmd2);
        break;
      case REDIRECT_OUT:
        redirect_out_cmd(cmd1, cmd2);
        break;
      case NOTHING:
        exe_cmd(cmd1);
        break;
      }
    }
  }
}
