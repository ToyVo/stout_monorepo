// Homework 9 Q2
// Template functions rotateLeft(), output(), and reverse()
#include <algorithm> // Needed for swap in reverse
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//********************************************************
// (1) implement template function ratateLeft(vector <T>& v)
// Rotates the vector circularly one place to the left.  *
//********************************************************

//**********************************************************
// (2) implement template function output(vector <T> v)
// Output the contents of the vector                       *
//**********************************************************

//**********************************************************
// (3) implement template function reverse(vector <T>& v)
// Reverse the contents of the vector                       *
//**********************************************************

int main(int argc, char **argv) {
  cout << "Testing 1: rotateLeft and output functions" << endl;
  // Initialize a vector of integers
  int SIZE = 5;
  vector<int> v;
  for (int i = 1; i < SIZE; i++)
    v.push_back(2 * i - 1);

  // output the entire vector while we rotate integers
  // one position left each time
  for (int i = 0; i < SIZE; i++) {
    output(v);
    cout << endl;
    rotateLeft(v);
  }
  cout << endl;

  // Initilaize a vector of String
  vector<string> vs;
  string as[] = {"a", "b", "c", "d", "e"};
  for (int i = 0; i < SIZE; i++)
    vs.push_back(as[i]);

  // output the entire vector while we rotate left the characters
  // one position left each time
  for (int i = 0; i < SIZE; i++) {
    output(vs);
    cout << endl;
    rotateLeft(vs);
  }

  cout << "\nTesting 2: reverse function" << endl;

  // Initialize a vector of 5 integers
  vector<int> vr;
  for (int k = 1; k < SIZE; k++) {
    vr.push_back(2 * k - 1);
  }
  // output the original vector
  cout << "Original vector is ";
  output(vr);

  // Reverse the vector and output the vector
  reverse(vr);

  cout << "\nReversed vector is ";
  output(vr);
  cout << endl;

  // Initialize a vector of strings
  vector<string> vsr;
  string asr[] = {"a", "b", "c", "d", "e"};
  for (int k = 0; k < SIZE; k++) {
    vsr.push_back(asr[k]);
  }

  // output the original vector
  cout << "Original vector is ";
  output(vsr);

  // Reverse the vector and output the vector
  reverse(vsr);

  cout << "\nReversed vector is ";
  output(vsr);
  cout << endl;

  system("pause");
  return 0;
}