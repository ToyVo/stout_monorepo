#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(const string &sname, const string &sid, const string &smajor,
                 int year)
    : SimplePerson(sname, sid), major(smajor), gradYear(year) {}

Student::~Student() {}

void Student::print() {
  SimplePerson::print();
  cout << "major: " << major << ", gradYear: " << gradYear << endl;
}

void Student::changeMajor(const string &newMajor) { major = newMajor; }
