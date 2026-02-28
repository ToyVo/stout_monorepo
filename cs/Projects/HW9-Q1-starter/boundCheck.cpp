// Homework 9 Q1
// String Bound Exceptions
// This program creates a subclas of string that
// performs bounds-checking and throws an exception
// if an attempt is made to index outside the bounds of string.

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class StrExcept {}; // String Out of Bounds Exception

// This is child of the string class that
// performs bounds checking and throws an exception
class BCheckString : public string {
private:
  string str;

public:
  // constructor
  BCheckString(string s);
  int length();

  // The overloaded [] operator t
  char operator[](int k);
};

// (1) implement BCheckString constructor
// This convert  constructor just calls the base class constructor
// using its constructor initialization list

BCheckString::BCheckString(string s) {
  str = s;
  string(str);
}

int BCheckString::length() { return str.length(); }

// (2) implement BCheckString member function operator[]
// 	The overloaded [] operator throws an exception if its parameter is out
// bounds (k value is less than 0 or k value is greater than or equal to the
// string length) otherwise it calls operator [] in the string base class

char BCheckString::operator[](int k) {
  if (k < 0 || k >= str.length())
    throw StrExcept();
  else
    return str[k];
}

int main() {
  // Explain program to user
  cout << "This program demonstrates bounds checking on string object.";

  // Get string from user and create boundCheck string object
  cout << "\nEnter a string: " << endl;
  string str;
  getline(cin, str);

  BCheckString handler(str);

  // Let user access characters at specified positions in the string
  // (3) implement try block and catch block for an exception handling.
  // The exception type thrown by operator[] is StrExcept

  try {
    cout << "Legitimate string positions are: " << 0 << ".."
         << handler.length() - 1 << endl;

    for (int k = 1; k <= 5; k++) {
      cout << "Enter an integer describing a position inside or outside the "
              "string: ";
      int pos;
      cin >> pos;
      cout << "The character at position " << pos << " is " << handler[pos]
           << endl;
    }
  }

  catch (StrExcept) {
    cout << "\nAccess violation in string." << endl;
  }

  system("pause");
  return 0;
}