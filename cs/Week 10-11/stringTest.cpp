// This program demonstrates string class in C++:
// 1. default constructor and copy constructor
// 2. the use of the string find and insert member functions.
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void simpleTest();
void formatTest();
string dollarFormat(string); // Prototype

int main(void) {
  simpleTest();
  formatTest();

  system("pause");
  return 0;
}

void simpleTest() {
  string greeting; // Default constructor
  greeting = "Hello";

  string name("William Smith"); // Convert constructor

  cout << greeting << ", " << name << endl;
}

void formatTest() {
  string input; // User input

  // Get the dollar amount from the user
  cout << "Enter a dollar amount in the form nnnnn.nn : ";
  cin >> input;

  // Display the formatted dollar amount
  cout << "Formatted amount:   " << dollarFormat(input) << endl;
}

//******************************************************
// Returns a $-formatted version of the input string.  *
//******************************************************
string dollarFormat(string original) {
  string formatted = original;
  int dp = formatted.find('.'); // Position of decimal point
  int pos = dp;                 // Search for comma position
  while (pos > 3) {
    pos = pos - 3;
    formatted.insert(pos, ",");
  }
  formatted.insert(0, "$");
  return formatted;
}