// This program uses two functions that accept addresses of variables as
// arguments. It also demonstrates a pointer to const parameter

#include <iostream>
#include <stdlib.h>

using namespace std;

// Function prototypes
void getNumber(int *);
void doubleValue(int *);
void swapValues(int *, int *);
void displayValues(const int *numbers, int size);

int main() {
  int number;
  int number2;

  // Call getNumber and pass the address of number
  getNumber(&number);

  // Call doubleValue and pass the address of number
  doubleValue(&number);

  // Display the value in number
  cout << "That value doubled is " << number << endl;

  // Array sizes
  const int SIZE = 6;

  // Define an array of const ints
  const int array1[SIZE] = {1, 2, 3, 4, 5, 6};

  // Define an array of non-const ints
  int array2[SIZE] = {2, 4, 6, 8, 10, 12};

  // Display the contents of the const array
  displayValues(array1, SIZE);

  // Display the contents of the non-const array
  displayValues(array2, SIZE);

  getNumber(&number);
  getNumber(&number2);

  cout << "n1: " << number << " n2: " << number2 << endl;

  swapValues(&number, &number2);

  cout << "n1: " << number << " n2: " << number2 << endl;

  system("pause");
  return 0;
}

//******************************************************
// Definition of getNumber. The parameter, input, is a *
// pointer. This function asks the user for a number.  *
// The value entered is stored in the variable         *
// pointed to by input.                                *
//******************************************************

void getNumber(int *input) {
  cout << "Enter an integer number: ";
  cin >> *input;
}

//******************************************************
// Definition of doubleValue. The parameter, val, is a *
// pointer. This function multiplies the variable      *
// pointed to by val by two.                           *
//******************************************************

void doubleValue(int *val) { *val *= 2; }

void swapValues(int *n1, int *n2) { swap(*n1, *n2); }

//***************************************************
// The displayValues function uses a pointer to     *
//***************************************************
void displayValues(const int *numbers, int size) {
  // Display all the values
  for (int count = 0; count < size; count++) {
    cout << *(numbers + count) << " ";
  }
  cout << endl;
}