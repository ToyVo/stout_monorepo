#include "rangeCheck.h"
#include <iostream>

using namespace std;

int main() {
  double root;
  rangeCheck square;
  cout << "enter in a number to get a square root" << endl;
  try {
    root = square.getInput();
    cout << "square root is: " << root << endl;
  } catch (rangeCheck::Negative) {
    cout << "Cannot square root a negative number" << endl;
  }
  system("pause");
  return 1;
}