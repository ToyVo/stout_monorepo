// ---------------------------------------------------------------------------
// SimplePerson.h
//
// Written by:    Wan D. Bae
// Last Modified: September, 2016
//
// Description:
// Example C++ class for use in CS 244
//
// ---------------------------------------------------------------------------
#pragma once // #pragma once is a pre-processor directive
             // it tells the compiler to include this header only
             // ONE time. This prevents the compiler from recursively
             // including this header and getting stuck (sort of)
             // in an infinite loop
             // e.g myMain.cpp includes
             //     me.h that includes you.h and you.h includes me.h
             //     so include me.h which includes you.h which includes me.h
             //     so include me.h which includes you.h which...
             //     and so on and so on

XXXXXXXX     // include iostream
    XXXXXXXX // include string

        XXXXXXXXXX // use standard namespace

    class SimplePerson {
public:
  XXXXXXXXXX                  // constructor prototype
      ~SimplePerson();        // destructor
  XXXXXXXX                    // print member function
      string getName() const; // constant getName function returns a string

  // Overload some friend operators to work with this class

  // Equality check, are two objects of SimplePerson the same?
  friend bool operator==(const SimplePerson &lhs, const SimplePerson &rhs);

  // "Output" operator so std::cout can output a SimplePerson object
  friend ostream &operator<<(ostream &ostr, const SimplePerson &sp);

private:
  string m_nameStr; // the prefix "m_" stands for member variable
  string m_idStr;   // it is just a naming convention
};
