#include "inheritance.h"

//*********************************************
// Constructor for the Person class.          *
//*********************************************
Person::Person() { setName(""); }

//*********************************************
// Constructor for the Student class.         *
//*********************************************
Student::Student(string sname, Discipline d, Person *adv) : Person(sname) {
  major = d;
  advisor = adv;
}

//*********************************************
// Constructor for the Faculty class.         *
//*********************************************
Faculty::Faculty(string fname, Discipline d) : Person(fname) { department = d; }

//*********************************************
// Constructor for the Faculty class.         *
//*********************************************
TFaculty::TFaculty(string fname, Discipline d, string title)
    : Faculty(fname, d) {
  setTitle(title);
}