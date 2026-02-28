#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

Employee::Employee() {
  setName("");
  setID(0);
  setDepartment("");
  setPosition("");
}
Employee::Employee(string n, int i) {
  setName(n);
  setID(i);
  setDepartment("");
  setPosition("");
}
Employee::Employee(string n, int i, string d, string p) {
  setName(n);
  setID(i);
  setDepartment(d);
  setPosition(p);
}
void Employee::setName(string n) { name = n; }
void Employee::setID(int i) { idNumber = i; }
void Employee::setDepartment(string d) { department = d; }
void Employee::setPosition(string p) { position = p; }
string Employee::getName() { return name; }
int Employee::getID() { return idNumber; }
string Employee::getDepartment() { return department; }
string Employee::getPosition() { return position; }
void Employee::print() {
  cout << "Employee Name: " << name << " ID: " << idNumber
       << " Department: " << department << " Position: " << position << endl;
}