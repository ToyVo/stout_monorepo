#include <iostream>

void printRandomNumbers(int len) {
  for (int i = 0; i < len; i++) {
    long number = random() % 1001 + 1000;
    std::cout << number << std::endl;
  }
}

int main() {
  int len;
  std::cin >> len;
  printRandomNumbers(len);
  return 0;
}
