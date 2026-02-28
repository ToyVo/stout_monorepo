#include "Gene.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "In the main method of GeneTest.cpp" << endl;
  string test = "acata";
  int points = 0;
  // Test the constructor
  Gene g(test);
  points += 5;
  cout << "Constructor works +5 points equal: " << points << endl;

  // Test the output operator <<
  cout << "Print Gene g with << " << g << endl << endl;
  points += 5;
  cout << "operator<< works +5 points equal: " << points << endl;

  // Test aCount()
  Gene g1("act");
  if (g1.aCount() == 1) {
    points += 5;
    cout << "aCount() works +5 points equal: " << points << endl;
  } else {
    cout << "Error: aCount() did not return the correct number" << endl;
  }
  // Test cCount
  if (g1.cCount() == 1) {
    points += 5;
    cout << "cCount() works +5 points equal: " << points << endl;
  } else {
    cout << "Error: cCount() did not return the correct number" << endl;
  }
  // Test gCount for 0 g in sequence
  if (g1.gCount() == 0) {
    points += 5;
    cout << "gCount() works +5 points equal: " << points << endl;
  } else {
    cout << "Error: gCount() did not return the correct number" << endl;
  }
  // Test tCount
  if (g1.tCount() == 1) {
    points += 5;
    cout << "tCount() works +5 points equal: " << points << endl;
  } else {
    cout << "Error: tCount() did not return the correct number" << endl;
  }

  // Test genes to see that they are equal
  // Case 1 is that they are equal

  Gene e1("atca");
  Gene e2("atca");

  // Are they equal for +2 points
  if (e1 == e2) {
    cout << "They are equal" << endl;
    points += 2;
    cout << "operator== works when genes are equal +2 points equal: " << points
         << endl;
  } else
    cout << "Error: operator== failed when genes are equal" << endl;

  // Can code determine that they are not equal +1
  Gene e3("atcag");
  Gene e4("atcat");
  if (e3 == e4) {
    cout << "Error: operator== failed when genes are NOT equal" << endl;
  } else {
    cout << "Test to see if " << e3 << " is equal to " << e4
         << " \nShould fail." << endl;

    points += 1;
    cout << "operator== works when genes are NOT equal +1 points equal: "
         << points << endl;
  }
  // Can code determine reverse to be equal?
  Gene e5("atcg");
  Gene e6("gcta");
  if (e5 == e6) {
    cout << e5 << " is equal to " << e6 << endl;
    points += 2;
    cout << "operator== works when genes are equal +2 points equal: " << points
         << endl;
  } else
    cout << "Error: operator== failed when genes are equal but reversed" << endl
         << e5 << "should be equal to " << e6 << endl;

  // Test copy constructor
  Gene s1("act");
  Gene s2 = s1; // calls Gene copy constructor
  cout << "s1 is " << s1 << endl;
  cout << "s2 is " << s2 << endl;
  cout << "s1 and s2 equal: " << (s1 == s2) << endl;
  s2.set(0, 'c');
  cout << "s2 is " << s2 << endl;
  if (s1 == s2) {
    cout << "S2 was changed after copy constructor call and S1 changed also. "
            "Fix copy constructor to get 5 points"
         << endl;
  } else {
    cout << "s1 and s2 not equal after copy constructor and change of s2 test: "
         << (s1 == s2) << " get 5 points" << endl;
    points += 5;
  }

  // Test the operator= to make a deep copy
  Gene s4("tata");
  Gene s3("gcgc");
  cout << "s4 and s3 equal: " << (s4 == s3) << endl;
  s3 = s4; // calls operator= in Gene and must make own copy of sequence for s3
  cout << "s4 and s3 equal operator= Test: " << (s4 == s3) << endl;
  s3.set(0, 'c'); // change first value of s3 (should not change s4)
  cout << "s3 is " << s3 << endl;
  cout << "s4 is " << s4 << endl;
  cout << "s4 and s3 equal operator= Change Test: " << (s4 == s3) << endl;
  if (s4 == s3) {
    cout << "S3 was changed after operator= call and S4 changed also. Fix "
            "operator= to get 5 points"
         << endl;
  } else {
    cout << "s1 and s2 not equal after operator= and change of s3 test: "
         << (s1 == s2) << " get 5 points" << endl;
    points += 5;
  }

  cout << "Final score is " << points << endl;
  cout << "Show me the destructor for the final five points." << endl;
  cout << endl;

  return 0;
}
