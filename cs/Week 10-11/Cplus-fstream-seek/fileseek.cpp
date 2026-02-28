// This program demonstrates the seekg function.
#include <cctype>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

int seekgTest();
int tellgTest();
int rewind();

int main() {

  rewind();
  system("pause");
  return 0;
}

int seekgTest() {
  // Variable to access file
  char ch;

  // Open the file for reading
  fstream file("letters.txt", ios::in);
  if (!file) {
    cout << "Error opening file.";
    return 1;
  }

  // Get fifth byte from beginning of alphabet file
  file.seekg(5L, ios::beg);
  file.get(ch);
  cout << "Byte 5 from beginning: " << ch << endl;

  // Get tenth byte from end of alphabet file
  file.seekg(-10L, ios::end);
  file.get(ch);
  cout << "Byte 10 from end: " << ch << endl;

  // Go forward three bytes from current position
  file.seekg(3L, ios::cur);
  file.get(ch);
  cout << "Byte 3 from current: " << ch << endl;

  // Close file
  file.close();
  return 0;
}

int tellgTest() {
  // Variables used to read the file
  long offset;
  char ch;
  char response; // User response

  // Create the file object and open the file
  fstream file("letters.txt", ios::in);
  if (!file) {
    cout << "Error opening file.";
    return 1;
  }
  // Work with the file
  do {
    // Where in the file am I?
    cout << "Currently at position " << file.tellg() << endl;

    // Get a file offset from the user.
    cout << "Enter an offset from the "
         << "beginning of the file: ";
    cin >> offset;

    // Read the character at the given offset
    file.seekg(offset, ios::beg);
    file.get(ch);
    cout << "Character read: " << ch << endl;
    cout << "Do it again? ";
    cin >> response;
  } while (toupper(response) == 'Y');

  file.close();
  return 0;
}

// Program shows how to rewind a file. It writes a
// text file and opens it for reading, then rewinds
// it to the beginning and reads it again.
int rewind() {
  // Variables needed to read or write file one
  // character at a time
  char ch;
  fstream ioFile("rewind.txt", ios::out);

  // Open file.
  if (!ioFile) {
    cout << "Error in trying to create file";
    return 0;
  }

  // Write to file and close
  ioFile << "All good dogs " << endl << "growl, bark, and eat." << endl;
  ioFile.close();

  // Open the file
  ioFile.open("rewind.txt", ios::in);
  if (!ioFile) {
    cout << "Error in trying to open file";
    return 0;
  }

  // Read the file and echo to screen
  ioFile.get(ch);
  while (!ioFile.fail()) {
    cout.put(ch);
    ioFile.get(ch);
  }

  // Rewind the file
  ioFile.clear();
  ioFile.seekg(0, ios::beg);

  // Read file again and echo to screen
  ioFile.get(ch);
  while (!ioFile.fail()) {
    cout.put(ch);
    ioFile.get(ch);
  }
  return 0;
}
