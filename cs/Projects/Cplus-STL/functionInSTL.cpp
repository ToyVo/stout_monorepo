
#include <algorithm> // Required for STL algorithms
#include <iostream>
#include <stdlib.h>
#include <vector> // Needed to use vectors

using namespace std;

void vectorDemo();
void stlAlgoDemo1();   // STL random_shuffle(), sort(), binary_search()
void stlAlgoDemo2();   // STL count()
void stlAlgoDemo3();   // STL max_element() and min_element()
void stlAlgoFind();    // STL find()
void stlAlgoForEach(); // STL for_each()
void doubleValue(int &val);

int main() {
  cout << "vector demo: \n" << endl;
  vectorDemo();

  cout << "STL random_shuffle(), sort(), binary_search() demo: \n" << endl;
  stlAlgoDemo1();

  cout << "STL count() demo: \n" << endl;
  stlAlgoDemo2();

  cout << "STL max_element() and min_element() demo: \n" << endl;
  stlAlgoDemo3();

  cout << "STL find() demo: \n" << endl;
  stlAlgoFind();

  cout << "STL for_each() demo: \n" << endl;
  stlAlgoForEach();

  system("pause");
  return 0;
}

// This program provides a simple demonstration of the vector STL template.
void vectorDemo() {
  vector<int> vect; // Create a vector of int

  for (int x = 0; x < 10; x++)
    vect.push_back(x * x);

  // Print everything using iterators
  vector<int>::iterator iter = vect.begin();
  while (iter != vect.end()) {
    cout << *iter << " ";
    iter++;
  }
  cout << endl;
}

// This program provides a simple demonstration of the STL algorithms.
// random_shuffle(), sort(), binary_search()
void stlAlgoDemo1() {
  vector<int> vect; // Define a vector object

  // Use push_back to push values into the vector
  for (int x = 0; x < 10; x++)
    vect.push_back(x * x);

  // Display the vector's elements
  cout << "The collection has " << vect.size() << " elements. Here they are:\n";

  for (int x = 0; x < vect.size(); x++)
    cout << vect[x] << " ";
  cout << endl;

  // Randomly shuffle the vector's contents
  random_shuffle(vect.begin(), vect.end());

  // Display the vector's elements
  cout << "The elements have been shuffled:\n";
  for (int x = 0; x < vect.size(); x++)
    cout << vect[x] << " ";
  cout << endl;

  // Now sort them
  sort(vect.begin(), vect.end());

  // Display the vector's elements again
  cout << "The elements have been sorted:\n";
  for (int x = 0; x < vect.size(); x++)
    cout << vect[x] << " ";
  cout << endl;

  // Now search for an element
  int val = 49;
  if (binary_search(vect.begin(), vect.end(), val))
    cout << "The value " << val << " was found in the vector.\n";
  else
    cout << "The value " << val << " was not found in the vector.\n";
}

// This program demonstrates the STL count()
void stlAlgoDemo2() {
  vector<int> values;
  vector<int>::iterator iter;

  // Store some values in the vector
  values.push_back(1);
  values.push_back(2);
  values.push_back(2);
  values.push_back(3);
  values.push_back(3);
  values.push_back(3);

  // Display the values in the vector
  cout << "The values in the vector are:\n";
  for (iter = values.begin(); iter != values.end(); iter++)
    cout << *iter << " ";
  cout << endl << endl;

  // Display the count of each number
  cout << "The number of 1s in the vector is ";
  cout << count(values.begin(), values.end(), 1) << endl;
  cout << "The number of 2s in the vector is ";
  cout << count(values.begin(), values.end(), 2) << endl;
  cout << "The number of 3s in the vector is ";
  cout << count(values.begin(), values.end(), 3) << endl;
}

// This program demonstrates the STL max_element and min_element algorithms.
void stlAlgoDemo3() {
  vector<int> numbers;
  vector<int>::iterator iter;

  // Store some numbers in the vector
  for (int x = 0; x < 10; x++)
    numbers.push_back(x);

  // Shuffle things up just for fun
  random_shuffle(numbers.begin(), numbers.end());

  // Display the numbers in the vector
  cout << "The numbers in the vector are:\n";
  for (iter = numbers.begin(); iter != numbers.end(); iter++)
    cout << *iter << " ";
  cout << endl;

  // Find the largest value in the vector
  iter = max_element(numbers.begin(), numbers.end());
  cout << "The largest value in the vector is " << *iter << endl;

  // Find the smallest value in the vector
  iter = min_element(numbers.begin(), numbers.end());
  cout << "The smallest value in the vector is " << *iter << endl;
}

// This program demonstrates the STL find algorithm.
void stlAlgoFind() {
  vector<int> numbers;
  vector<int>::iterator iter;

  // Store some numbers in the vector
  for (int x = 0; x < 10; x++)
    numbers.push_back(x);

  // Display the numbers in the vector
  cout << "The numbers in the vector are:\n";
  for (iter = numbers.begin(); iter != numbers.end(); iter++)
    cout << *iter << " ";
  cout << endl << endl;

  // Find 7 in the vector
  iter = find(numbers.begin(), numbers.end(), 7);
  cout << "The value searched for is " << *iter << endl;
}

// This program demonstrates the for_each find algorithm
void stlAlgoForEach() {
  vector<int> numbers;
  vector<int>::iterator iter;

  // Store some numbers in the vector
  for (int x = 0; x < 10; x++)
    numbers.push_back(x);

  // Display the numbers in the vector
  cout << "The numbers in the vector are:\n";
  for (iter = numbers.begin(); iter != numbers.end(); iter++)
    cout << *iter << " ";
  cout << endl;

  // Double the values in the vector
  for_each(numbers.begin(), numbers.end(), doubleValue);

  // Display the numbers in the vector again
  cout << "Now the numbers in the vector are:\n";
  for (iter = numbers.begin(); iter != numbers.end(); iter++)
    cout << *iter << " ";
  cout << endl;
}

//********************************************************
// Function doubleValue. This function accepts an int    *
// reference as its argument. The value of the argument  *
// is doubled.                                           *
//********************************************************
void doubleValue(int &val) { val *= 2; }