// ***********************************************************
//      DynamicArray class declaration
// ***********************************************************

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "d_except.h" // for rangeError exception
#include <iostream>

using namespace std;

template <class T> class DynamicArray {
public:
  // constructor
  // Postconditions: an empty vector with size = 5  and a specified capacity.
  DynamicArray(int capacity = 5);

  // copy constructor uses existing DynamicArray obj to create new
  // DynamicArray(*this) Postcondition: creates current DynamicArray (*this) as
  // a copy of obj
  DynamicArray(const DynamicArray &obj);

  // destructor
  // Postcondition: the dynamic array is destroyed and memory returned to the
  // heap
  ~DynamicArray();

  // Precondition: the vector is not empty and index < vSize-1
  // Postcondition: returns the value at index.
  int get(int index) const;

  // Precondition: 0 <= index < vSize-1
  // Postcondition: update location index with value
  void set(int value, int index);

  // Postcondition: value appended at end of vector with size increased by 1
  void push_back(int value);

  // insert value in nth index position of the vector.
  // Postcondition: value at index n with the rest of the elements moved up and
  // size+1
  void insert(int value, int index);

  // remove element at index location in the vector.
  // Precondition: vector is not empty, else throws the underflowError exception
  // Postcondition: element at index removed and size--
  void remove(int index);

  // return current size of elements stored in Dynamic Array
  int size() const;

  // return true if vector is empty and false otherwise
  bool empty() const;

  // return the current capacity of the dynamic array
  int capacity() const;

  // print variable values and array for debugging
  void printVector() const;

  // Member function to overload the assignment operator
  DynamicArray &operator=(const DynamicArray &rhs);

  // Must make copy of dynamic array from rhs for *this (or left hand side of =)
  //  compares twodynamic arrays for the same sizes and array values
  friend bool operator==(DynamicArray &lhs, DynamicArray &rhs);

  // output the elements in vArr array in order.
  friend ostream &operator<<(ostream &ostr, const DynamicArray &da);

private:
  int vCapacity; // amount of available space
  int vSize;     // number of elements in the list
  T *vArr;       // the dynamic array

  // called by public functions only if size of array needs to exceed vCapacity.
  // the vector capacity to n elements, copies the existing
  // elements to the new space if copy == true, and deletes
  // the old dynamic array. throws the memoryAllocationError
  // exception if memory allocation fails
  void growArray(int n, bool copy);
};

// ***********************************************************
//      DynamicArray class implementation
// ***********************************************************

// Implement DynamicArray here
// private function growArray
template <class T> void DynamicArray::growArray(int n, bool copy) {
  z
      // Declare int pointer newArr to a new array of n elements
      T *newArr = new T[n];

  // throw an exception if memory not allocated
  if (newArr == NULL)
    throw memoryAllocationError("memory allocation failure in growArray");

  // if copy is true, loop to copy elements in vArr to newArr array
  if (copy) {
    for (int i = 0; i < vSize; i++)
      newArr[i] = vArr[i];
  }

  // if original vArr not Null delete it
  if (vArr != NULL)
    delete[] vArr;

  // assign newArr to vArr. Update capacity to n
  vArr = newArr;
  vCapacity = n;
}

// constructors
//  Postconditions: an empty vector with size = 5  and a specified capacity.
template <class T> DynamicArray::DynamicArray(int capacity) {
  // initialize three data members
  vSize = 0;
  vCapacity = capacity;
  vArr = NULL;

  // use growArray to set capacity and initialize array, but no elements to
  // copy.
  growArray(vCapacity, false);

  // set all to zero
  for (int i = 0; i < vCapacity; i++) {
    vArr[i] = 0;
  }
}
// Add other constructors here
// Copy Constructor
template <class T> DynamicArray::DynamicArray(const DynamicArray &obj) {
  vArr = NULL;
  vSize = obj.vSize;
  growArray(obj.vCapacity, false);

  for (int i = 0; i < obj.vSize; i++)
    vArr[i] = obj.vArr[i];
}

// Destructor
template <class T> DynamicArray::~DynamicArray() {
  if (vArr != NULL)
    delete[] vArr;
  cout << "Did you remember to delete the array on the vector?" << endl;
}

// Insert other functions here
// Compare two DynamicArray objects
template <class T> bool operator==(DynamicArray &lhs, DynamicArray &rhs) {
  if (lhs.size() != rhs.size())
    return false;
  for (int i = 0; i < lhs.vSize; i++) {
    if (lhs.vArr[i] != rhs.vArr[i])
      return false;
  }
  return true;
}

// Custom print out method
template <class T> ostream &operator<<(ostream &ostr, const DynamicArray &da) {
  for (int i = 0; i < da.vSize; i++)
    ostr << da.vArr[i] << " ";
  ostr << endl;
  return ostr;
}

// Assignment operator
template <class T>
DynamicArray &DynamicArray::operator=(const DynamicArray &rhs) {
  growArray(rhs.vCapacity, false);
  vSize = rhs.vSize;
  for (int i = 0; i < rhs.vSize; i++)
    vArr[i] = rhs.vArr[i];
  return *this;
}

// Getter for capacity
template <class T> int DynamicArray::capacity() const { return vCapacity; }

// Determines if array is empty
template <class T> bool DynamicArray::empty() const {
  if (vSize == 0)
    return true;
  return false;
}

// Getter for size
template <class T> int DynamicArray::size() const { return vSize; }

// Remove an element at index, shifting other left to fill the gap
template <class T> void DynamicArray::remove(int index) {
  for (int i = index + 1; i < vSize; i++)
    vArr[i - 1] = vArr[i];
  vSize--;
}

// Add an element at index, shifting existing+ to the right
template <class T> void DynamicArray::insert(int value, int index) {
  if (vSize + 1 > vCapacity)
    growArray(vCapacity * 2, true);
  for (int i = vSize; i > index; i--)
    vArr[i + 1] = vArr[i];
  vArr[index] = value;
  vSize++;
}

// Add element to end of array
template <class T> void DynamicArray::push_back(int value) {
  if (vSize + 1 > vCapacity)
    growArray(vCapacity * 2, true);
  vArr[vSize] = value;
  vSize++;
}

// Set indexed location to specified value
template <class T> void DynamicArray::set(int value, int index) {
  vArr[index] = value;
}

// Retrieve value at location index
template <class T> int DynamicArray::get(int index) const {
  return vArr[index];
}

// for debugging by printing out all values in a DynamicArray
template <class T> void DynamicArray::printVector() const {
  cout << "Size is " << vSize << " capacity is " << vCapacity << endl;

  if (vArr != NULL) {
    cout << "Elements are: " << endl;
    for (int i = 1; i <= vSize; i++) {
      cout << vArr[i - 1] << " ";
      if (i % 10 == 0)
        cout << endl;
    }
  }
  cout << endl << endl;
}

#endif