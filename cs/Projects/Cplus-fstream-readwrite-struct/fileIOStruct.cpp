#include <cctype> // for toupper
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

const int NAME_SIZE = 51, ADDR_SIZE = 51, PHONE_SIZE = 14;

struct Info {
  char name[NAME_SIZE];
  int age;
  char address1[ADDR_SIZE];
  char address2[ADDR_SIZE];
  char phone[PHONE_SIZE];
};

int writeInfo(); // This function demonstrates the use of a structure variable
                 // to store a record of information to a file.
int readInfo(); // This function demonstrates the use of a structure variable to
                // read a record of information from a file.

int main() {
  readInfo();

  system("pause");

  return 0;
}

int readInfo() {
  Info person;   // Store person information
  char response; // User response

  // Create file object and open file for binary reading
  fstream people("people.dat", ios::in | ios::binary);
  if (!people) {
    cout << "Error opening file. Program aborting.\n";
    return 1;
  }

  // Label the output
  cout << "Here are the people in the file:\n\n";

  // Read one structure at a time and echo to screen
  people.read(reinterpret_cast<char *>(&person), sizeof(person));
  while (!people.eof()) {
    cout << "Name: ";
    cout << person.name << endl;
    cout << "Age: ";
    cout << person.age << endl;
    cout << "Address line 1: ";
    cout << person.address1 << endl;
    cout << "Address line 2: ";
    cout << person.address2 << endl;
    cout << "Phone: ";
    cout << person.phone << endl;
    cout << "\nStrike any key to see the next record.\n";
    cin.get(response);
    people.read(reinterpret_cast<char *>(&person), sizeof(person));
  }
  cout << "That's all the information in the file!\n";
  people.close();
  return 0;
}

int writeInfo() {
  Info person;   // Store information about a person
  char response; // User response

  string input; // Used to read strings

  // Create file object and open file
  fstream people("people.dat", ios::out | ios::binary);
  if (!people) {
    cout << "Error opening file. Program aborting.\n";
    return 1;
  }

  // Keep getting information from user and writing it
  // to the file in binary mode
  do {
    cout << "Enter person information:\n";
    cout << "Name: ";
    getline(cin, input);
    strcpy(person.name, input.c_str());
    cout << "Age: ";
    cin >> person.age;
    cin.ignore(); // Skip over remaining newline
    cout << "Address line 1: ";
    getline(cin, input);
    strcpy(person.address1, input.c_str());
    cout << "Address line 2: ";
    getline(cin, input);
    strcpy(person.address2, input.c_str());
    cout << "Phone: ";
    getline(cin, input);
    strcpy(person.phone, input.c_str());
    people.write(reinterpret_cast<char *>(&person), sizeof(person));
    cout << "Do you want to enter another record? ";
    cin >> response;
    cin.ignore();
  } while (toupper(response) == 'Y');

  // Close file
  people.close();
  return 0;
}