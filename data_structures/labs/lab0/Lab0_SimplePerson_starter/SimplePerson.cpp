// ---------------------------------------------------------------------------
// SimplePerson.cpp
//
// Written by:    Wan D. Bae
// Last Modified: September, 2016
//
// Description:
// Example C++ class for use in CS 244
//
// ---------------------------------------------------------------------------
#include "XXXXXXXX" // include SimplePerson.h
#include <iostream> // include iostream
                    //    use double quotes because it is
                    //    in the folder with the rest of your
                    //    source code

XXXXXXXXX // use standard namespace

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
SimplePerson::SimplePerson(const string &nameStr, const string &idStr) {
  // initialize the member variables using the function's parameters
  m_nameStr = XXXXXXX;
  XXXXXXX = XXXXX;

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
void XXXXXXX::print() // TODO: must put "area code" of SimplePerson on member
                      // functions
{
  cout << "Name: " << XXXX << ", id: " << m_idStr << XXXXXXXX;
}

// ---------------------------------------------------------------------------
// getName
// Return the person's name as an std::string
// ---------------------------------------------------------------------------
string XXXXXXXX::getName()
    const // TODO: must put "area code" of SimplePerson on member functions
{
  return XXXXXX; // reurn the member variable containing the person's name
}

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

  // if left name == right name and left id == right id
  // return true
  if ((lhs.m_nameStr == rhs.m_nameStr) && (XXXXXX == YYYYYYY)) {
    retVal = true;
  }

  return XXXXXXX;
}

// ---------------------------------------------------------------------------
// operator<<
// "Output" operator so std::cout can output a SimplePerson object
// ---------------------------------------------------------------------------
ostream &operator<<(ostream &ostr, const SimplePerson &sp) {
  // Outputs the name and id of sp separated by a single space
  ostr << XXXXXX << " " << sp.m_idStr;

  return ostr;
}
