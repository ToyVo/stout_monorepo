#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int readWrite(); // this function demonstreates reading and writing a file
                 // through an fstream object
int errorTest(); // This program demonstrates the return value of the stream
                 // object error testing member functions.
void showState(fstream &file);
int failTest(); // This program shows the behavior of the >> operator on files
                // that contain spaces as part of the information. The program
                // reads the contents of the file and transfers those contents
                // to standard output.

int main() {
  // readWrite();
  // errorTest();
  failTest();

  system("pause");
  return 0;
}

int readWrite() {
  fstream inOutFile;
  string word; // Used to read a word from the file

  // Open the file
  inOutFile.open("inout.txt");
  if (!inOutFile) {
    cout << "The file was not found." << endl;
    return 1;
  }

  // Read and print every word already in the file
  while (inOutFile >> word) {
    cout << word << endl;
  }

  // Clear end of file flag to allow additional file operations
  inOutFile.clear();

  // Write a word to the file and close the file
  inOutFile << "Hello3" << endl;
  inOutFile.close();
  return 0;
}

int errorTest() {
  // Open a file, write a number, and show file status
  fstream testFile("stuff.dat", ios::out);
  if (testFile.fail()) {
    cout << "cannot open the file.\n";
    return 1;
  }
  int num = 10;
  cout << "Writing to the file.\n";
  testFile << num;

  showState(testFile);
  testFile.close();

  // Open the same file, read the number, show status
  testFile.open("stuff.dat", ios::in);
  if (testFile.fail()) {
    cout << "cannot open the file.\n";
    return 1;
  }
  cout << "Reading from the file.\n";
  testFile >> num;
  showState(testFile);

  // Attempt an invalid read, and show status
  cout << "Forcing a bad read operation.\n";
  testFile >> num;

  showState(testFile);

  // Close file and quit.
  testFile.close();
  return 0;
}

//*********************************************************
// Definition of function showState. This function uses   *
// an fstream reference as its parameter. The return      *
// values of the eof(), fail(), bad(), and good() member  *
// functions is displayed. The clear() function is called *
// before the function returns.                           *
//*********************************************************
void showState(fstream &file) {
  cout << "File Status:\n";
  cout << "  eof bit: " << file.eof() << endl;
  cout << "  fail bit: " << file.fail() << endl;
  cout << "  bad bit: " << file.bad() << endl;
  cout << "  good bit: " << file.good() << endl;
  file.clear(); // Clear any bad bits
}

int failTest() {
  // variables needed to read file
  fstream file;
  string input;

  // Open the file
  file.open("murphy.txt", ios::in);
  if (!file) {
    cout << "File open error!" << endl;
    return 1;
  }

  // Read the file and echo to screen
  file >> input;
  while (!file.fail()) {
    cout << input;
    file >> input;
  }
  cout << endl;

  // Close the file
  file.close();
  return 0;
}