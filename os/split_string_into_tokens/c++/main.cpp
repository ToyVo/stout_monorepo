#include <iostream>
#include <string>

int main() {
  std::cout << "Enter in a sentence" << std::endl;
  std::string sentenceInput;
  getline(std::cin, sentenceInput);
  std::cout << "Enter in a word to search for" << std::endl;
  std::string wordInput;
  std::cin >> wordInput;
  std::cout << "Searching " << sentenceInput << " for " << wordInput
            << std::endl;
  if (sentenceInput.find(wordInput) != std::string::npos) {
    std::cout << "FOUND" << std::endl;
  } else {
    std::cout << "NOT FOUND" << std::endl;
  }
  return 0;
}
