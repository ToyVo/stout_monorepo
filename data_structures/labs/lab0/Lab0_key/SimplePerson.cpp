// ---------------------------------------------------------------------------
// SimplePerson.cpp
//
// Written by:    Wan D. Bae
// Last Modified: September, 2013
//
// Description:
// Example C++ class for use in CS 244
//
// ---------------------------------------------------------------------------
#include "SimplePerson.h"
#include <iostream>

using namespace std;

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
SimplePerson::SimplePerson(const string &nameStr, const string &idStr) {
  m_nameStr = nameStr;
  m_idStr = idStr;

  // for debugging output something:
  cout << "SimplePerson constructor is called" << endl;
}

// ---------------------------------------------------------------------------
// Destructor
// ---------------------------------------------------------------------------
SimplePerson::~SimplePerson() {
  // for debugging output something:
  cout << "SimplePerson destructor is called" << endl;
}

// ---------------------------------------------------------------------------
// print
// Output the person's name and id on a snigle line (newline included)
// ---------------------------------------------------------------------------
void SimplePerson::print() {
  cout << "Name: " << m_nameStr << ", id: " << m_idStr << endl;
}

// ---------------------------------------------------------------------------
// getName
// Return the person's name as an std::string
// ---------------------------------------------------------------------------
string SimplePerson::getName() const { return m_nameStr; }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// global friend operators follow
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// operator==
// Equality check, are two objects of SimplePerson the same?
// lhs = Left Hand Side      rhs = Right Hand Side
// ---------------------------------------------------------------------------
bool operator==(const SimplePerson &lhs, const SimplePerson &rhs) {
  bool retVal = false;

  if ((lhs.m_nameStr == rhs.m_nameStr) && (lhs.m_idStr == rhs.m_idStr)) {
    retVal = true;
  }

  return retVal;
}

// ---------------------------------------------------------------------------
// operator<<
// "Output" operator so std::cout can output a SimplePerson object
// Outputs the name and id of sp separated by a single space
// ---------------------------------------------------------------------------
ostream &operator<<(ostream &ostr, const SimplePerson &sp) {
  ostr << sp.m_nameStr << " " << sp.m_idStr;

  return ostr;
}
