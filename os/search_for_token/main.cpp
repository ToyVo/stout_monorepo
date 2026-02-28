#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool isTokenInCollection(std::string const &token,
                         std::string const &sentence) {
  return sentence.find(token) != std::string::npos;
}

bool isTokenInCollection(std::string const &token,
                         std::vector<std::string> const &sentence) {
  for (auto const &word : sentence) {
    if (token == word) {
      return true;
    }
  }
  return false;
}

int main() {
  std::vector<std::string> tokens{};

  std::cout << "Enter in a sentence" << std::endl;
  std::string sentenceInput;
  getline(std::cin, sentenceInput);

  {
    std::stringstream stringStream(sentenceInput);
    std::string token;
    while (std::getline(stringStream, token, ' ')) {
      tokens.push_back(token);
    }
  }

  for (auto const &token : tokens) {
    std::cout << token << std::endl;
  }

  char *cStringArray[tokens.size() + 1];
  cStringArray[tokens.size()] = nullptr;

  for (int i{0}; i < tokens.size(); i++) {
    cStringArray[i] = const_cast<char *>(tokens[i].c_str());
  }

  for (auto const &cString : cStringArray) {
    if (cString != nullptr) {
      std::cout << cString << std::endl;
    } else {
      std::cout << "NULL" << std::endl;
    }
  }

  std::cout << "enter in a word to search for" << std::endl;

  std::string input;
  std::cin >> input;

  std::cout << "string,string " << isTokenInCollection(input, sentenceInput)
            << std::endl;
  std::cout << "string,string vector " << isTokenInCollection(input, tokens)
            << std::endl;

  return 0;
}
