#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

void change(int x, int y) {
  int temp = x;
  x = y;
  y = temp;
}

int main() {
  int x = 10, y = 20;
  cout << "Before change: " << x << ", " << y << endl;
  change(x, y);

  cout << "After change: " << x << ", " << y << endl;

  return EXIT_SUCCESS;
}
