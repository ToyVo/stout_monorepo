#include <iostream>

int main() {
  while (true)
    std::cout << "\a";

  for (int a = 0; a < 5; a++) {
    int b = 0;
    static int c = 0;
    b++;
    c++;
    std::cout << "b: " << b << " c: " << c << std::endl;
  }
  system("pause");
}