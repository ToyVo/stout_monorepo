// This program uses the  getline  function to read
// a line of information from the file.
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int getlineTest(); // This function uses the  getline  function to read a line
                   // of information from the file.
int getlineDelimiter(); // This function demonstrates the getline function with
                        // a user-specified delimiter.
int readOneChar();      // This program demonstrates the use of the get member
                        // functions of the istream class

int main() {
  getlineTest();
  getlineDelimiter();
  readOneChar();

  system("pause");

  return 0;
}

int getlineTest() {
  // Variables needed for file input
  fstream nameFile;
  string input;

  // Open the file
  nameFile.open("murphy.txt", ios::in);
  if (!nameFile) {
    cout << "File open error!" << endl;
    return 1;
  }

  // Read first line of the file
  getline(nameFile, input);
  while (nameFile) {
    // If successful, print line and read another line
    cout << input << endl;
    getline(nameFile, input);
  }

  // Close the file
  nameFile.close();
  return 0;
}

int getlineDelimiter() {
  // Variable needed to read file
  string input;

  // Open the file.
  fstream dataFile("address.txt", ios::in);
  if (!dataFile) {
    cout << "Error opening file.";
    return 1;
  }

  // Read lines terminated by '$' sign and output
  getline(dataFile, input, '$');
  while (!dataFile.fail()) {
    cout << input << endl;
    getline(dataFile, input, '$');
  }

  // Close the file
  dataFile.close();
  return 0;
}

int readOneChar() {
  // Variables needed to read file one character at a time
  string fileName;
  fstream file;
  char ch; // character read from the file

  // Get file name and open file
  cout << "Enter a file name: ";
  cin >> fileName;

  file.open(fileName, ios::in);
  if (!file) {
    cout << fileName << " could not be opened.\n";
    exit(1);
  }

  // Read file one character at a time and echo to screen
  ch = file.get();
  while (ch != EOF) {
    cout << ch;
    ch = file.get();
  }
  cout << endl;

  // Close file
  file.close();
  return 0;
}