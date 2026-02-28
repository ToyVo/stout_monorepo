// File:SequenceTest.cpp
// the program uses tests the Sequence objects

#include <iostream>
using namespace std;
#include "Sequence.h"

int main() {
  cout << "In the main method of SequenceTest.cpp" << endl;
  string test = "acata";
  int points = 0;

  // Test the constructor
  Sequence g(test);
  points += 5;
  cout << "Constructor works +5 points equal: " << points << endl;

  // Test size() method
  if (g.size() == 5) {
    points += 5;
    cout << "size() works +5 points equal: " << points << endl;
  } else {
    cout << "Error: size() did not work" << endl;
  }

  // Test the output operator <<
  cout << "Print Sequence g with << " << g << endl << endl;
  points += 5;
  cout << "operator<< works +5 points equal: " << points << endl;

  // Test getSequence()
  char *seq = g.getSequence();
  bool testSequence = false;
  for (int i = 0; i < test.size(); i++) {
    if (seq[i] != test[i])
      break;
    if (i = test.size() - 1)
      testSequence = true;
  }
  if (testSequence) {
    points += 5;
    cout << "getSequence() works +5 points equal: " << points << endl;
  } else {
    cout << "Error: getSequence() did not return the sequence properly" << endl;
  }

  // Test Sequences to see that they are equal
  // Case 1 is that they are equal

  Sequence e1("atca");
  Sequence e2("atca");

  // Are they equal for +2 points
  if (e1 == e2) {
    cout << "They are equal" << endl;
    points += 2;
    cout << "operator== works when Sequences are equal +2 points equal: "
         << points << endl;
  } else
    cout << "Error: operator== failed when Sequences are equal" << endl;

  // Can code determine that they are not equal +1
  Sequence e3("atcag");
  Sequence e4("atcat");
  if (e3 == e4) {
    cout << "Error: operator== failed when Sequences are NOT equal" << endl;
  } else {
    cout << "Test to see if " << e3 << " is equal to " << e4
         << " \nShould fail." << endl;

    points += 1;
    cout << "operator== works when Sequences are NOT equal +1 points equal: "
         << points << endl;
  }

  // Can code determine reverse to be equal?
  Sequence e5("atcg");
  Sequence e6("gcta");
  if (e5 == e6) {
    cout << e5 << " is equal to " << e6 << endl;
    points += 2;
    cout << "operator== works when Sequences are equal +2 points equal: "
         << points << endl;
  } else
    cout << "Error: operator== failed when Sequences are equal but reversed"
         << endl
         << e5 << "should be equal to " << e6 << endl;

  // Testing of operator< for subsequence finding

  Sequence full("actactaggaaatcg");
  Sequence sub1("act");
  Sequence sub2("tcga");  // off the end
  Sequence sub3("aggat"); // find reverse
  Sequence sub5("t");

  // Case 1
  if (sub1 < full) {
    cout << "Case 1: " << sub1 << " is a subsequence of " << full << endl;
    points += 4;
    cout << "operator< works for Case 1 gives +4 points equal: " << points
         << endl;
  } else
    cout << "Failed subsequence Case 1: " << sub1 << " is a subsequence of "
         << full << endl;

  // Case 2
  if (!(sub2 < full)) {
    cout << "Case 2: Correct " << sub2 << " is NOT a subsequence of " << full
         << endl;
    points += 4;
    cout << "operator< works and returns fales for an extra  +4 points equal: "
         << points << endl;
  } else
    cout << "Failed subsequence Case 2 when not a subsequence" << endl;

  // Case 3 equal or same Sequences
  if (full < full) {
    cout << "Case 3: " << full << " is a subsequence of " << full << endl;
    points += 4;
    cout << "operator< works for Case 3 gives +4 points equal: " << points
         << endl;
  } else
    cout << "Failed subsequence Case 3: " << full << " is a subsequence of "
         << full << endl;

  // Case 4 reverse of sub3 is in full
  if (sub3 < full) {
    cout << "Case 4: " << sub3 << " is a subsequence of " << full << endl;
    points += 4;
    cout << "operator< works for Case 4 gives +4 points equal: " << points
         << endl;
  } else
    cout << "Failed subsequence Case 4: " << sub3 << " is a subsequence of "
         << full << endl;

  // Case 5 reverse of sub5 is in full
  if (sub5 < full) {
    cout << "Case 5: " << sub5 << " is a subsequence of " << full << endl;
    points += 4;
    cout << "operator< works for Case 5 gives +4 points equal: " << points
         << endl;
  } else
    cout << "Failed subsequence Case 5: " << sub5 << " is a subsequence of "
         << full << endl;

  cout << "Final score is " << points << endl;
  cout
      << "If you delete the array of sequence in destructor, then you are done!"
      << endl;
  cout << endl;

  return 0;
}
