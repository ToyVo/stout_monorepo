#include <cstdlib> // Provides EXIT_SUCCESS
#include <ctime>
#include <iostream> // Provides cin, cout

using namespace std; // Use C++ Standard namespace

// header description of all methods implemented after main method
template <class T> void printArray(const T data[], int n);
template <class T> void selectionSort(T data[], int n);
template <class T> void swap(T *a, T *b);

const int size = 10; // Elements in each array. Do not hard code sizes.

// Main method to test implementation of above methods.
int main() {
  // create arrays for different types
  int intArr[size];
  char charArr[size];

  // initialize random seed
  srand(time(NULL));

  int num;
  for (int i = 0; i < size; i++) {
    // generate secret number between 1 and 100
    num = rand() % 100 + 1;
    intArr[i] = num;
  }

  cout << "(intArr before sorting): ";
  printArray(intArr, size);

  // call selectionSort() by passing array name and size
  selectionSort(intArr, size);

  cout << "(intArr after sorting): ";
  printArray(intArr, size);

  char ch;
  for (int i = 0; i < size; i++) {
    // generate charactors
    ch = (char)(rand() % 26 + 1) + 64;
    charArr[i] = ch;
  }

  cout << "(charArr before sorting): ";
  printArray(charArr, size);

  // call selectionSort() by passing array name and size
  selectionSort(charArr, size);

  cout << "(charArr after sorting): ";
  printArray(charArr, size);

  return EXIT_SUCCESS;
}

// method to print out an array with 10 items per line
// Precondition: data contains n elements
// Postcondition: output data array to screen with 10 elements per line
template <class T> void printArray(const T data[], int n) {
  cout << endl << "The array elements are ";
  for (int i = 0; i < n; i++) {
    if (i % 10 == 0)
      cout << endl;
    cout << data[i] << " ";
  }
  cout << endl << endl;
}

// Precondition: data contains n elements
// Postcondition: data is sorted in ascending order
template <class T> void selectionSort(T data[], int n) {
  int smallest;
  int smallestIndex;

  for (int i = 0; i < n - 1; i++) {
    // set smallest to the first element
    smallest = data[i];
    smallestIndex = i;

    // find smallest element
    for (int j = i + 1; j < n; j++) {
      if (data[j] < smallest) {
        smallest = data[j];
        smallestIndex = j;
      }
    }
    // swap with smallest element
    swap(data[i], data[smallestIndex]);
  }
}

// swap two values that the parameter pointers point
template <class T> void swap(T *a, T *b) {
  T temp = *a;
  *a = *b;
  *b = temp;
}
