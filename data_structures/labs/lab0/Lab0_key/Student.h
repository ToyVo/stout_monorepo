#ifndef STUDENT_H
#define STUDENT_H

#include "SimplePerson.h"
#include <iostream>
#include <string>

using namespace std;

class Student : public SimplePerson {
public:
  Student(const string &sname, const string &sid, const string &smajor,
          int year);
  ~Student();
  void print();
  void changeMajor(const string &newMajor);

private:
  string major;
  int gradYear;
};
#endif
