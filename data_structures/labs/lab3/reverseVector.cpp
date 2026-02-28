// Problem 1
// Collin Diekvoss

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// (1) implement function reverseVector() as a template function
// reveres the elements of the vector
// parameters: iterator to first element and iterator to last element
template <class T> void reverceVector(T itn1, T itn2) {
  while (itn1 < itn2) {
    swap(*itn1, *itn2);
    itn1++;
    itn2--;
  }
}

// (2) implement function print() as a template function
// print the vector
// parameters: iterator to first element and iterator to last element
template <class T> void print(T itn1, T itn2) {
  while (itn1 <= itn2) {
    cout << *itn1 << endl;
    itn1++;
  }
}

// implement main() function
int main() {
  // *** (3) Test on integer vector reverse ***
  // (3-1) create an integer vector of size 0 and name it intList
  vector<int> intList;

  // (3-2) call function push_back() 7 times to store 1, 2, 3, 4, 5, 6, 7
  for (int i = 1; i <= 7; i++) {
    intList.push_back(i);
  }

  // (3-3) get iterator to first element
  vector<int>::iterator firstPos = intList.begin();

  // (3-4) get iterator to last element
  vector<int>::iterator lastPos = intList.end() - 1;

  cout << "*** integer vector reverse using iterators ***" << endl;
  cout << "intList before reverse: ";

  // (3-5) call print() function to print the vector
  print(firstPos, lastPos);

  // (3-6) call reverseVector() function to reverse the elements of the vector
  reverceVector(firstPos, lastPos);

  cout << "intList after reverse: ";

  // (3-7) call print() function to print the vector
  print(firstPos, lastPos);

  // *** Test on string vector reverse ***
  // (4-1) create a string vector with size 0 and name it strList
  vector<string> strList;

  // (4-2) call function push_back() to store "Spring", "Summer", "Fall",
  // "Winter"
  strList.push_back("Spring");
  strList.push_back("Summer");
  strList.push_back("Fall");
  strList.push_back("Winter");

  // (4-3) get iterator to first element
  vector<string>::iterator sFirstPos = strList.begin();

  // (4-4) get iterator to last element
  vector<string>::iterator sLastPos = strList.end() - 1;

  cout << "*** stringi vector reverse using iterators ***" << endl;
  cout << "stringList before reverse: ";

  // (4-5) call function print() to print the vector
  print(sFirstPos, sLastPos);

  // (4-6) call reverseVector() function to reverse the elements of the vector
  reverceVector(sFirstPos, sLastPos);

  cout << "stringList after reverse: ";

  // (4-7) call function print() to print the vector
  print(sFirstPos, sLastPos);

  return 0;
}
