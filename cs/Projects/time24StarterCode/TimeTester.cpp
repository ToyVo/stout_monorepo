// File:TimeTester.cpp
// the program uses tests the time24 objects to compute the time

#include <iostream>
using namespace std;
#include "time24.h"

int main() {
  cout << "In the main method of TimeTester.cpp" << endl;
  time24 t1;
  t1.writeTime();
  /*******************************************************
  Problem 3 of worksheet
  Create the following time24 objects
          t1 with initial value of 7:43
          t2 with initial value of 9:00 (specify only one integer to create this
  object) t3 with intial value of 10:20 t4 with no intial values use writeTime()
  method to output the intial values of each object
  */

  // Problem 4 Using the new subtractHour method subtract 7 hours from t3 and
  // output results

  try {
    // Problem 10

  } catch (const rangeError &re) // Handle exception defined in d_except.h
  {
    char ch;
    cerr << re.what() << endl;
    cin >> ch;
  }
  cout << endl;
  // Complete problem 11

  // Complete problem 12
}
