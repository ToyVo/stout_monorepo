// This program demonstrates the strcmp and atoi functions.
#include <cstdlib> // For atoi
#include <cstring> // For strcmp
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
  // Array used to read numbers in string form
  const int LENGTH = 20;
  char input[LENGTH];

  int total = 0,  // Running total
      count = 0;  // Number of numbers read
  double average; // Average

  // Read numbers and compute total of numbers
  cout << "This program will average a series of numbers.\n";
  cout << "Enter the first number or Q to quit: ";
  cin.getline(input, LENGTH);

  while ((strcmp(input, "Q") != 0) && (strcmp(input, "q") != 0)) {
    // Keep a running total
    total += atoi(input);

    // Keep track of how many numbers are entered
    count++;

    // Are there more?
    cout << "Enter the next number or Q to quit: ";
    cin.getline(input, LENGTH);
  }

  // Compute and print average
  if (count != 0) {
    average = double(total) / count;
    cout << "average: " << average << endl;
  }

  system("pause");
  return 0;
}