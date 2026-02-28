#include "Encryption.h"

#include <iostream>
using namespace std;

//**************************************************
// Constructor opens the input and output file.    *
//**************************************************
Encryption::Encryption(const char *inFileName, const char *outFileName) {
  // Attempt to open the input and output files
  inFile.open(inFileName);
  outFile.open(outFileName);

  if (!inFile) {
    cerr << "The file " << inFileName << " cannot be opened.";
    system("pause");
    exit(1);
  }

  if (!outFile) {
    cerr << "The file " << outFileName << " cannot be opened.";
    system("pause");
    exit(1);
  }
}

//**************************************************
// Destructor closes files.                         *
//**************************************************
Encryption::~Encryption() {
  // Close the input and output files
  inFile.close();
  outFile.close();
}

//*****************************************************
// Encrypt function uses the virtual transform         *
// member function to transform individual characters. *
//*****************************************************
void Encryption::encrypt() {
  // Read in characters from the input file
  char ch;
  inFile.get(ch);

  // While the input file is still valid
  while (!inFile.fail()) {
    // Encrypt the character and write it to output
    char transCh = transform(ch);
    outFile.put(transCh);
    inFile.get(ch);
  }
}
