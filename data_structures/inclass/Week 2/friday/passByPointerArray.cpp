#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  int num[5] = {10, 20, 30, 40, 50};

  cout << "Before change: ";
  for (int i = 0; i < 5; i++) {
    cout << num[i] << ", ";
  }

  for (int i = 0; i < 5; i++) {
  }

  cout << "After change: ";
  for (int i = 0; i < 5; i++) {
    cout << num[i] << ", ";
  }

  return EXIT_SUCCESS;
}