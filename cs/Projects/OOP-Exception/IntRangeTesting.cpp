// This program demonstrates the use of object-oriented
// exception handling.
#include "IntRange1.h"
#include "IntRange2.h"
#include "IntRange3.h"
#include <iostream>

using namespace std;

void rangeTesting1();
void rangeTesting2();
void rangeTesting3();

int main() {
  rangeTesting1();

  rangeTesting2();

  rangeTesting3();

  system("pause");
  return 0;
}

void rangeTesting1() {
  IntRange1 range(5, 10);
  int userValue;

  cout << "Enter a value in the range 5 - 10: ";
  try {
    userValue = range.getInput();
    cout << "You entered " << userValue << endl;
  } catch (IntRange1::OutOfRange) {
    cout << "That value is out of range.\n";
  }
  cout << "End of the program.\n";
}

void rangeTesting2() {
  IntRange2 range(5, 10);
  int userValue;

  cout << "Enter a value in the range 5 - 10: ";
  try {
    userValue = range.getInput();
    cout << "You entered " << userValue << endl;
  } catch (IntRange2::TooLow) {
    cout << "That value is too low.\n";
  } catch (IntRange2::TooHigh) {
    cout << "That value is too high.\n";
  }
  cout << "End of the program.\n";
}

void rangeTesting3() {
  IntRange3 range(5, 10);
  int userValue;

  cout << "Enter a value in the range 5 - 10: ";
  try {
    userValue = range.getInput();
    cout << "You entered " << userValue << endl;
  } catch (IntRange3::OutOfRange ex) {
    cout << "That value " << ex.value << " is out of range.\n";
  }
  cout << "End of the program.\n";
}