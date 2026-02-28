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
  Person(string n, string p) {
    name = n;
    phone = p;
  }
  void setName(string name) { this->name = name; }
  string getName() const { return name; }
  void setPhone(string phone) { this->phone = phone; }
  string getPhone() const { return phone; }
};

class Vehicle {
protected:
  string registrationNumber;
  Person *owner;

public:
  virtual const void printInfo() = 0;
  const string getRegistrationNumber() { return registrationNumber; }
  void setRegistrationNumber(string reg) { registrationNumber = reg; }
  const Person *getOwner() { return owner; }
  void setOwner(Person *own) { owner = own; }
};

class Car : public Vehicle {
private:
  string color;

public:
  Car(string reg, Person *own, string col) {
    registrationNumber = reg;
    owner = own;
    color = col;
  }
  virtual const void printInfo() {
    cout << color << " Car " << registrationNumber
         << " owned by: " << owner->getName()
         << " whos phone number is: " << owner->getPhone() << endl;
  }
};

class Motorcycle : public Vehicle {
private:
  bool hasSideCar;

public:
  Motorcycle(string reg, Person *own, bool side) {
    registrationNumber = reg;
    owner = own;
    hasSideCar = side;
  }
  virtual const void printInfo() {
    if (hasSideCar)
      cout << "Motorcycle with a side car ";
    else
      cout << "Motorcycle without a side car ";
    cout << registrationNumber << " owned by: " << owner->getName()
         << " whos phone number is: " << owner->getPhone() << endl;
  }
};

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