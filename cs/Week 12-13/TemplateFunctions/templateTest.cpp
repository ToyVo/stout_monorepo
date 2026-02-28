// This program uses a function template.
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int square(int number) { return number * number; }

double square(double number) { return number * number; }

// (1) Implement template function square() for any type
// and then remove two square functions above

int minimum(int arr[], int size) {
  int smallest = arr[0];
  for (int k = 1; k < size; k++) {
    if (arr[k] < smallest)
      smallest = arr[k];
  }
  return smallest;
}

string minimum(string arr[], int size) {
  string smallest = arr[0];
  for (int k = 1; k < size; k++) {
    if (arr[k] < smallest)
      smallest = arr[k];
  }
  return smallest;
}

// (2) Implement tempate function minimum() for any type of an array
// and then remove two minimum() functions above

int main() {
  cout << setprecision(5);
  cout << "Square Testing \n" << endl;
  // Get an integer and compute its square
  cout << "Enter an integer: ";
  int iValue;
  cin >> iValue;

  // The compiler creates int square(int) at the first
  // occurrence of a call to square with an int argument
  cout << "The square is " << square(iValue);

  // Get a double and compute its square
  cout << "\nEnter a double: ";
  double dValue;
  cin >> dValue;

  // The compiler creates double square(double)at the first
  // occurrence of a call to square with a double argument
  cout << "The square is " << square(dValue) << endl;

  cout << "Minimum Testing \n" << endl;
  // The compiler creates int minimum(int [], int)
  // when you pass an array of int
  int arr1[] = {40, 20, 35};
  cout << "The minimum number is " << minimum(arr1, 3) << endl;

  // The compiler creates string minimum(string [], int)
  // when you pass an array of string
  string arr2[] = {"Zoe", "Snoopy", "Bob", "Waldorf"};
  cout << "The minimum string is " << minimum(arr2, 4) << endl;

  system("pause");
  return 0;
}