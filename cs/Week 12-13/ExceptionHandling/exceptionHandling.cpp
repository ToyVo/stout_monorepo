// This program illustrates exception handling.
#include <iostream>
#include <new>
#include <stdlib.h>
#include <string>

using namespace std;

// Function prototype
double divide(double numerator, double denominator);

int main() {
  int num1, num2;
  double quotient;

  // Exception Testing with a handler
  cout << "Exception testing with a handler" << endl;
  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  try {
    quotient = divide(num1, num2);
    cout << "The quotient is " << quotient << endl;
  } catch (string exceptionString) {
    cout << exceptionString;
  }

  // Exception Testing for bad_alloc Exception
  cout << "Exception testing for bad_alloc" << endl;
  int *p;
  try {
    p = new int[2];
    p[0] = 10;
    p[1] = 20;
  } catch (bad_alloc) {
    cout << "Memory cannot be allocated.";
    exit(1);
  }
  cout << p[0] << "  " << p[1] << endl;
  ;

  system("pause");
  return 0;
}

double divide(double numerator, double denominator) {
  if (denominator == 0)
    throw string("ERROR: Cannot divide by zero.\n");
  else
    return numerator / denominator;
}