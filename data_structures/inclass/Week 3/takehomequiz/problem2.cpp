#include <iostream>

using namespace std;

int main() {
  int i = 23, j = 55;
  cout << "i = " << i << " j = " << j << endl;
  cout << "i = " << &i << " j = " << &j << endl;

  // part a
  //&i = 4;

  // change values
  i = 7, j = 8;
  // print again
  cout << "i = " << i << " j = " << j << endl;
  cout << "i = " << &i << " j = " << &j << endl;

  // part b
  // j = &i;
  // part c
  // j = (int)&i;

  return 0;
}