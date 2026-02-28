// This program demonstrates abstract base
// classes and pure virtual functions.
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Person {
private:
  string name;
  string phone;

public:
  Person(string name, string phone) {
    this->name = name;
    this->phone = phone;
  }
  void setName(string name) { this->name = name; }
  string getName() const { return name; }
  void setPhone(string phone) { this->phone = phone; }
  string getPhone() const { return phone; }
};

// (1) implement Vehicle class

// (2) implement Car class

// (3) implement Motorcycle class

int main() {
  // Create array of pointers to Vehicles of various types
  const int NUM_VEHICLES = 3;

  Vehicle *vArray[] = {
      new Car("1000", new Person("Cole Nuwen", "715-309-2121"), "white"),
      new Car("2000", new Person("Amy Drew", "303-618-3000"), "yellow"),
      new Motorcycle("m1000", new Person("Zach Horak", "232-444-5000"), false)};

  // print Vehicle information
  for (int i = 0; i < NUM_VEHICLES; i++) {
    vArray[i]->printInfo();
  }

  system("pause");
  return 0;
}