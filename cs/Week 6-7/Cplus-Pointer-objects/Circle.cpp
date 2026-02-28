// This program illustrates the use of constructors
// and destructors in the allocation and deallocation of memory.
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Squares {
private:
  int length; // How long is the sequence
  int *sq;    // Dynamically allocated array

public:
  // Constructor allocates storage for sequence
  // of squares and creates the sequence
  Squares(int len);

  // Desctructor deallocates storage
  ~Squares();

  // Print the sequence
  void print();
};

//***********************************************
// Constructor						            *
//***********************************************
Squares::Squares(int len) {
  length = len;
  sq = new int[length];
  for (int k = 0; k < length; k++) {
    sq[k] = (k + 1) * (k + 1);
  }
  // Trace
  cout << "Construct an object of size " << length << endl;
}

//***********************************************
// Destructor    					            *
//***********************************************
Squares::~Squares() {
  delete[] sq;
  // Trace
  cout << "Destructor for object of size " << length << endl;
}

//***********************************************
// Member function that prints the elements *
//***********************************************
void Squares::print() {
  for (int k = 0; k < length; k++)
    cout << sq[k] << "  ";
  cout << endl;
}

// function prototype
void outputSquares(Squares *sqPtr);

int main() {
  Squares sqs(5);
  cout << "The first 5 squares are: ";
  sqs.print();

  // Main allocates a Squares object
  Squares *sqPtr = new Squares(3);
  outputSquares(sqPtr);
  // Main deallocates the Squares object
  delete sqPtr;

  system("pause");
  return 0;
}

//***********************************************
// local function that outputs the sequence of  *
// squares in a Squares object                  *
//***********************************************
void outputSquares(Squares *sqPtr) {
  cout << "The list of squares is: ";
  sqPtr->print();
}