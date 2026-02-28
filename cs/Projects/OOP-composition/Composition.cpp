#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
// This program illustrates aggregation, composition
// and object lifetimes.
#include <iostream>
#include <string>

using namespace std;

class Date {
  string month;
  int day, year;
  int personID; // ID of person whose birthday this is.
public:
  Date(string m, int d, int y, int id)
      : month(m), day(d), year(y), personID(id) {
    cout << "Date-Of-Birth object for person " << personID
         << " has been created.\n";
  }
  ~Date() {
    cout << "Date-Of-Birth object for person " << personID
         << " has been destroyed.\n";
  }
};

class Country {
  string name;

public:
  Country(string name) : name(name) {
    cout << "A Country object has been created.\n";
  }
  ~Country() { cout << "A Country object has been destroyed.\n"; }
};

class Person {
  string name;
  Date dateOfBirth;
  int personID; // Person identification number (PID)
  Country *pCountry;

public:
  Person(string name, string month, int day, int year, Country *pC)
      : name(name), dateOfBirth(month, day, year, Person::uniquePersonID),
        personID(Person::uniquePersonID), pCountry(pC) {
    cout << "Person object " << personID << " has been created.\n";
    Person::uniquePersonID++;
  }
  ~Person() {
    cout << "Person object " << personID << " has been destroyed.\n";
  }
  static int uniquePersonID; // Used to generate PIDs
};

// Define the static class variable
int Person::uniquePersonID = 1;

int main() {
  // Create a Country object
  Country usa("USA");
  // Create a Person object
  Person *p = new Person("Peter Lee", "January", 1, 1985, &usa);
  // Create another Person object
  Person p1("Eva Gustafson", "May", 15, 1992, &usa);
  cout << "Now there are two people.\n";
  // Delete the first person
  delete p;
  cout << "Now there is only one.\n";
  // The second person will go out of scope when main returns

  system("pause");
  return 0;
}