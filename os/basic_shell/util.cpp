//
// Created by Collin Diekvoss on 3/4/20.
//

#include "util.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

PipeType is_token_pipeable(const std::string &token) {
  PipeType result = NOTHING;
  if (token == "|")
    result = PIPE;
  else if (token == "<")
    result = REDIRECT_IN;
  else if (token == ">")
    result = REDIRECT_OUT;

  return result;
}

void convert_str_to_c_string_array(const std::string &cmd,
                                   char **cStringArray) {
  std::vector<std::string> tokens;
  std::stringstream stream(cmd);
  std::string token;
  while (stream >> token) {
    tokens.push_back(token);
  }

  cStringArray[tokens.size()] = nullptr;
  for (int i = 0; i < tokens.size(); i++) {
    cStringArray[i] = const_cast<char *>(tokens[i].c_str());
  }
}

int get_number_of_tokens(const std::string &cmd) {
  int total = 0;
  for (char const &character : cmd) {
    if (character == ' ')
      total++;
  }
  return total + 1;
}
