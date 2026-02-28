#include <iostream>

using namespace std;

int main() {
  int i = 7;
  int *pOne;
  float x = 0.00;

  cout << "i = " << i << "\t&i" << &i << endl;
  pOne = &i;

  cout << "pOne = " << pOne << endl;

  // pOne = &x;

  cout << "pOne = " << pOne << endl;

  return 0;
}