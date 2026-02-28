// Collin Diekvoss

#include <algorithm> // Provides sort function
#include <cstdlib>   // Provides EXIT_SUCCESS
#include <ctime>     // Provides clock_gettime function
#include <iostream>  // Provides cin, cout

using namespace std; // Use C++ Standard namespace

// header description of all methods implemented after main method
int linearSearch(int data[], int n, int findValue);
int binarySearch(int data[], int n, int findValue);
void printArray(const int data[], int n);
static double TimeSpecToMilliSeconds(struct timespec *ts);

int counter = 0;              // global variable to count calls in searches
const int arrayLength = 1000; // Elements in each array. Do not hard code sizes.

// Main method to test implementation of above methods.
int main() {
  // create empty array1
  int array1[arrayLength];

  // fill the array with values, 1 to arrayLength, then print it
  for (int i = 0; i < arrayLength; i++)
    array1[i] = i + 1;

  printArray(array1, arrayLength);

  cout << endl
       << "*** Simple Testing for Linear search and Binary search ***" << endl
       << endl;

  counter = 0;
  int index10Linear = linearSearch(array1, arrayLength, 10);
  cout << "linear search for key element 10 takes counter of " << counter
       << " and found in array1[" << index10Linear << "]" << endl;

  counter = 0;
  int index10Binary = binarySearch(array1, arrayLength, 10);
  cout << "binarySearch for key element 10 takes counter of " << counter
       << " and found in array1[" << index10Linear << "]" << endl;

  // Uncomment to search for multiple values after linear and binary search
  // debugged.
  cout << endl << "*** Linear vs. Binary Comparisons ***" << endl << endl;

  // varaibles to get clocktime
  struct timespec start, end;
  double elapsedSeconds;

  // test Linear search for the values of 10, 20, 30, ... upto arrayLength
  int sum = 0, numSearches = 0;

  // get current clocktime
  clock_gettime(CLOCK_MONOTONIC, &start);

  for (int i = 10; i < arrayLength; i = i + 10) {
    counter = 0;
    linearSearch(array1, arrayLength, i);
    sum = sum + counter;
    numSearches++;
  }
  // get current clocktime
  clock_gettime(CLOCK_MONOTONIC, &end);

  // calculate elapsed time in milliseconds and print it
  elapsedSeconds =
      TimeSpecToMilliSeconds(&end) - TimeSpecToMilliSeconds(&start);

  cout << "Time for linear search in milliseconds: " << elapsedSeconds << endl;
  cout << "The average number of comparisons per linear search is "
       << sum / numSearches << endl
       << endl;

  // test Binary search for the values of 10, 20, 30, ... upto arrayLength
  sum = 0, numSearches = 0;

  // get current clocktime
  clock_gettime(CLOCK_MONOTONIC, &start);

  for (int i = 10; i < arrayLength; i = i + 10) {
    counter = 0;
    binarySearch(array1, arrayLength, i);
    sum = sum + counter;
    numSearches++;
  }

  // get current clocktime
  clock_gettime(CLOCK_MONOTONIC, &end);

  // calculated elapsed time and print it
  elapsedSeconds =
      TimeSpecToMilliSeconds(&end) - TimeSpecToMilliSeconds(&start);

  cout << "Time for Binary search in milliseconds: " << elapsedSeconds << endl;
  cout << "The average number of comparisons per binary search is "
       << sum / numSearches << endl
       << endl;

  return EXIT_SUCCESS;
}

// Precondition: data contains n elements. Searching data for number findValue
// Postcondition: returns index of findValue or -1 if not in data
// Insert code of algorithm developed in class
int linearSearch(int data[], int n, int findValue) {
  counter = 0; // variable to count number of loops

  // incrament through all items and compare to findValue
  for (int i = 0; i < n; i++) {
    if (findValue == data[i])
      return i;
    counter++;
  }

  return -1;
}

// Precondition: data in sorted order and contains n elements. Searching data
// for number findValue Postcondition: returns index of findValue or -1 if not
// in data Insert code for algorithm developed in class
int binarySearch(int data[], int n, int findValue) {
  counter = 0; // variable to count number of loops
  int left = 0, right = n - 1, middle = n / 2; // variables to store the sides

  while (left <= right) {
    counter++;

    // check if the current middle is findValue
    if (data[middle] == findValue)
      return middle;

    // change right side to make the scope smaller to find
    if (data[middle] > findValue) {
      right = middle - 1;
      middle = (right - left) / 2 + left;
    }

    // change left size to lower scope
    if (data[middle] < findValue) {
      left = middle + 1;
      middle = (right - left) / 2 + left;
    }
  }
  return -1; // failed to find it
}

// method to print out an array with 10 items per line
void printArray(const int data[], int n) {
  // Precondition: data contains n elements
  // Postcondition: output data array to screen with 10 elements per line
  cout << endl << "The array elements are: ";
  for (int i = 0; i < n; i++) {
    if (i % 20 == 0)
      cout << endl;
    cout << data[i] << " ";
  }
  cout << endl << endl;
}

static double TimeSpecToMilliSeconds(struct timespec *ts) {
  return (double)ts->tv_sec * 1000 + (double)ts->tv_nsec / 1000000.0;
}
