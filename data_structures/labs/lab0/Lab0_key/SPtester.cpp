//---------------------------------------------------------------------------
// SPtester.cpp
//
// Written by: Wan D. Bae
// Last Modified: 09/12/2017
//
// Description:
// Main routine to test an
// example C++ class for use in CS 244
//
// ---------------------------------------------------------------------------
#include "Student.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  SimplePerson someone("Dog Doggit", "111777");

  // test getName() member function of SimplePerson
  string tempName = someone.getName();
  cout << "Name is set to: " << tempName << endl;

  // test print() member function of SimplePerson
  someone.print();

  // test operator<< friend of SimplePerson
  cout << "cout says: " << someone << endl;

  // test operator==
  SimplePerson catRatter("Cat Ratter", "234567");
  SimplePerson dogger2("Dog Doggit", "555777");
  SimplePerson dogger3("Dogget Dog", "111777");
  SimplePerson someone2("Dog Doggit", "111777");

  if (catRatter == someone) {
    cout << "fail 1\n";
  } else {
    cout << "pass 1\n";
  }

  if (dogger2 == someone) {
    cout << "fail 2\n";
  } else {
    cout << "pass 2\n";
  }

  if (dogger3 == someone) {
    cout << "fail 3\n";
  } else {
    cout << "pass 3\n";
  }

  if (someone2 == someone) {
    cout << "pass 4\n";
  } else {
    cout << "fail 4\n";
  }

  if (someone == someone) {
    cout << "pass 5\n";
  } else {
    cout << "fail 5\n";
  }

  Student s1("Tim", "22-678", "AMCS", 2011);
  s1.print();

  Student *s2 = new Student("Carol", "34-989", "Physics", 2014);
  s2->print();

  s2->changeMajor("AMCS");
  s2->print();

  delete s2;

  return EXIT_SUCCESS;
}
