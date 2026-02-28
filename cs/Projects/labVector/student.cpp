#include "student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student() {
  setName("NULL");
  setPhone("NULL");
}

Student::Student(string n, string p) {
  setName(n);
  setPhone(p);
}

void Student::setAll(string n, string p) {
  setName(n);
  setPhone(p);
}

void Student::setName(string n) { name = n; }

void Student::setPhone(string p) { phone = p; }

string Student::getName() { return name; }

string Student::getPhone() { return phone; }

void Student::print() { cout << name << " " << phone << endl; }