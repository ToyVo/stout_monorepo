#include "Gene.h"
#include <cstdlib>
#include <iostream>
#include <string>

//****************************************************************
// Gene class testing program
// You should have Gene.h and Gene.cpp implemented (successfully)
// before your start implementing this program.
//****************************************************************

using namespace std;

int main() {
  cout << "In the main method of GeneTest.cpp" << endl;
  string test = "acata";

  // Test the constructor

  Gene gene1(test);

  // Test the output operator <<

  cout << gene1 << endl;

  // Test aCount()

  cout << "Number of a's " << gene1.aCount() << endl;

  // Test cCount

  cout << "Number of c's " << gene1.cCount() << endl;

  // Test gCount for 0 g in sequence

  cout << "Number of g's " << gene1.gCount() << endl;

  // Test tCount

  cout << "Number of t's " << gene1.tCount() << endl;

  // Test genes to see that they are equal
  Gene e1("atca");
  Gene e2("atca");

  if (e1 == e2) {
    cout << "e1 and e2 are equal" << endl;
  } else {
    cout << "e1 and e2 are not equal" << endl;
  }

  // Can code determine that they are not equal
  Gene e3("atcag");
  Gene e4("atcat");

  if (e3 == e4) {
    cout << "e3 and e4 are equal" << endl;
  } else {
    cout << "e3 and e4 are not equal" << endl;
  }

  // Can code determine reverse to be equal?
  Gene e5("atcg");
  Gene e6("gcta");

  if (e5 == e6) {
    cout << "e5 and e6 reversed are equal" << endl;
  } else {
    cout << "e5 and e6 reversed are not equal" << endl;
  }

  // Test copy constructor

  Gene gene2(gene1);

  cout << gene2 << endl;

  // Test the operator= to make a deep copy
  Gene s4("tata");
  Gene s3("gcgc");

  cout << s3 << endl;
  cout << s4 << endl;

  s3 = s4;

  cout << s3 << endl;
  cout << s4 << endl;

  return EXIT_SUCCESS;
}
