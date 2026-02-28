#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <cstdlib>
#include <iostream>
using namespace std;

template <class T> class SimpleVector {
private:
  T *aptr;
  int arraySize;
  void subError() const; // Handles subscripts out of range
public:
  SimpleVector(int);                  // Constructor
  SimpleVector(const SimpleVector &); // Copy constructor
  ~SimpleVector();                    // Destructor
  int size() const;
  T &operator[](int); // Overloaded [] operator
  void print() const; // outputs the array elements
};

//*******************************************************
// Constructor for SimpleVector class. Sets the size    *
// of the array and allocates memory for it.            *
//*******************************************************

//******************************************************
// Copy Constructor for SimpleVector class.            *
//******************************************************

//*****************************************************
// Destructor for SimpleVector class.                 *
//*****************************************************

//******************************************************
// subError function. Displays an error message and    *
// terminates the program when a subscript is out of   *
// range.                                              *
//******************************************************

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

//********************************************************
// prints all the entries is the array.                  *
//********************************************************

//********************************************************
// returns the size of the array.                  *
//********************************************************

#endif