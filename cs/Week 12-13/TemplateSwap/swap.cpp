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

  // (1) call swap function for swapping two characters

  cout << "After swap: " << firstChar << " " << secondChar << endl << endl;

  // Get and swap two ints
  int firstInt, secondInt;
  cout << "Enter two integers: ";
  cin >> firstInt >> secondInt;
  cout << "Inputs: " << firstInt << " " << secondInt << endl;

  // (2) call swap function for swapping two integers

  cout << "After swap: " << firstInt << " " << secondInt << endl << endl;
  ;

  // Get and swap two strings
  cout << "Enter two strings: ";
  string firstString, secondString;
  cin >> firstString >> secondString;
  cout << "Inputs: " << firstString << " " << secondString << endl;

  // (3) call swap function for swapping two strings

  cout << "after swap: " << firstString << " " << secondString << endl;

  system("pause");
  return 0;
}