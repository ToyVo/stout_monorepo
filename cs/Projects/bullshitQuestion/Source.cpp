#include <iostream>
using namespace std;

void modify(int &a, int &b) {

  a = 20;

  b = 5;
}

int main() {

  int x = 10;

  int y = 1;

  modify(x, y);

  cout << (x + y) << endl;

  system("pause");
  return 0;
}