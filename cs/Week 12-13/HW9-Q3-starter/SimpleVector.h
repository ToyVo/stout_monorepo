// Homework 9 Q3:
// SimpleVector.h
// You will need to implement push_back() and pop_back() template functions

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <cstdlib>
#include <iostream>
using namespace std;

template <class T> class SimpleVector {
private:
  T *aptr;
  int arraySize;
  void subError(); // Handles subscripts out of range
public:
  SimpleVector() // Default constructor
  {
    aptr = 0;
    arraySize = 0;
  }
  SimpleVector(int);                  // Constructor
  SimpleVector(const SimpleVector &); // Copy constructor
  ~SimpleVector();                    // Destructor
  int size() { return arraySize; }
  T &operator[](int); // Overloaded [] operator
  void print() const; // outputs the array elements

  void push_back(T); // newly added function (implemention needed)
  T pop_back();      // newly added function (implemention needed)
};

//****************************************************************
//          Constructor for SimpleVector class                   *
// Sets the size of the array and allocates memory for it.       *
//****************************************************************
template <class T> SimpleVector<T>::SimpleVector(int s) {
  arraySize = s;
  aptr = new T[s];
  for (int count = 0; count < arraySize; count++)
    *(aptr + count) = 0;
}

//*********************************************
// Copy Constructor for SimpleVector class    *
//*********************************************
template <class T> SimpleVector<T>::SimpleVector(const SimpleVector &obj) {
  arraySize = obj.arraySize;
  aptr = new T[arraySize];
  for (int count = 0; count < arraySize; count++)
    *(aptr + count) = *(obj.aptr + count);
}

// *************************************
// Destructor for SimpleVector class   *
// *************************************
template <class T> SimpleVector<T>::~SimpleVector() {
  if (arraySize > 0)
    delete[] aptr;
}

//************************************************************
//               SubError function                           *
// Displays an error message and terminates the program when *
// a subscript is out of range.                              *
//************************************************************
template <class T> void SimpleVector<T>::subError() {
  cout << "ERROR: Subscript out of range.\n";
  exit(0);
}

//***********************************************************
//             Overloaded [] operator                       *
// This function returns a reference to the element         *
// in the array indexed by the subscript.                   *
//***********************************************************
template <class T> T &SimpleVector<T>::operator[](int sub) {
  if (sub < 0 || sub >= arraySize)
    subError();
  return aptr[sub];
}

//********************************************************
// prints all the entries is the array.                  *
//********************************************************
template <class T> void SimpleVector<T>::print() const {
  for (int k = 0; k < arraySize; k++)
    cout << aptr[k] << "  ";
  cout << endl;
}

//***************************************************************
//                   (1) push_back(T val)                       *
// The push_back function pushes its argument onto the back     *
// Of the vector.                                               *
//***************************************************************

// *****************************************************
//                (2) pop_back()                       *
// The pop_back function removes the last element      *
// Of the vector. It also returns that value.          *
// *****************************************************

#endif