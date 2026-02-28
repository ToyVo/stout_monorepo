// This program illustrates inheritance and member function overriding.
#include "inheritance.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

// These arrays of string are used to output
// values of enumerated types.
const string dName[] = {"Archeology", "Biology", "Computer Science"};

const string cName[] = {"Freshman", "Sophomore", "Junior", "Senior"};

int main() {
  // New constructor allows specification of title
  TFaculty prof("Indiana Jones", ARCHEOLOGY, "Dr.");
  Student st("Sean Bolster", ARCHEOLOGY, &prof);

  // Use the new TFaculty version of getName
  cout << prof.getName() << " teaches " << dName[prof.getDepartment()] << "."
       << endl;

  // This call uses the Person version of getName
  Person *pAdvisor = st.getAdvisor();
  cout << st.getName() << "\'s advisor is " << pAdvisor->getName() << ".";

  system("pause");
  return 0;
}