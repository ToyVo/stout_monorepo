// This program shows that local variables do not retain their values between
// function calls. It also shows how a static local variable works.
#include <iostream>
#include <stdlib.h>

using namespace std;

void showLocal();  // Function prototype
void showStatic(); // Function prototype

int main() {
  showLocal();
  showLocal();

  // Call the showStatic function five times
  for (int count = 0; count < 5; count++)
    showStatic();

  system("pause");
  return 0;
}

/******************************************************
 *                       showLocal                    *
 * This function sets, displays, and then changes the *
 * value of local variable localNum before returning. *
 ******************************************************/
void showLocal() {
  int localNum = 5; // Local variable
  cout << "LocalNum is " << localNum << endl;
}

/**************************************************
 *                   showStatic                   *
 * This function keeps track of how many times it *
 * has been called by incrementing a static local *
 * variable, numCalls, each time it is called.    *
 **************************************************/
void showStatic() {
  static int numCalls = 0; // Static local variable
  numCalls++;
  cout << "This function has been called " << numCalls << " times." << endl;
}