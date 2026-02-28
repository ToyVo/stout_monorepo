// This is a tester program for DynamicArray class

#include "DynamicArray.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  cout << "Welcome to DynamicArrayTester" << endl;
  DynamicArray da1(2);

  da1.push_back(11);
  da1.insert(72, 1);
  da1.remove(1);
  da1.push_back(68);
  da1.set(98, 1);
  da1.printVector();

  cout << "Is da1 empty? " << da1.empty() << endl;
  cout << "The size is? " << da1.size() << endl;
  cout << "The capacity is? " << da1.capacity() << endl;

  DynamicArray da2;

  da2 = da1;
  da2.printVector();
  da1.printVector();

  cout << (da1 == da2) << endl;

  // perform operations on da1 to test your code

  return EXIT_SUCCESS;
}
