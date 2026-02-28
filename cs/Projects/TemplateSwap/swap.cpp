// This program demonstrates the use of the swap function template.
#include <algorithm> // Needed for swap function
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
  // Get and swap two chars
  char firstChar, secondChar;
  cout << "Enter two characters: ";
  cin >> firstChar >> secondChar;
  cout << "Inputs: " << firstChar << " " << secondChar << endl;

  swap(firstChar, secondChar);

  cout << "After swap: " << firstChar << " " << secondChar << endl << endl;

  // Get and swap two ints
  int firstInt, secondInt;
  cout << "Enter two integers: ";
  cin >> firstInt >> secondInt;
  cout << "Inputs: " << firstInt << " " << secondInt << endl;

  swap(firstInt, secondInt);

  cout << "After swap: " << firstInt << " " << secondInt << endl << endl;
  ;

  // Get and swap two strings
  cout << "Enter two strings: ";
  string firstString, secondString;
  cin >> firstString >> secondString;
  cout << "Inputs: " << firstString << " " << secondString << endl;

  swap(firstString, secondString);

  cout << "after swap: " << firstString << " " << secondString << endl;

  system("pause");
  return 0;
}