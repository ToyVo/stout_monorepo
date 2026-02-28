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
void Encryption::encrypt(int k) {
  // Read in characters from the input file
  char ch;
  inFile.get(ch);

  // While the input file is still valid
  while (!inFile.fail()) {
    // Encrypt the character and write it to output
    char transCh = transform(ch, k);
    outFile.put(transCh);
    inFile.get(ch);
  }
}

SimpleEncryption::SimpleEncryption(const char *inFileName,
                                   const char *outFileName)
    : Encryption(inFileName, outFileName) {}

// 'Transform' a letter by shifting it forward by 1
// this is known as a 'shift cipher' and is very easy to hack.
char SimpleEncryption::transform(char ch, int k) const {
  // Add the key value (we use an integer instead of a char for more precision)
  int trans = ch + k;

  // If it goes past ‘z’ wrap back around to ‘a'
  /*if(trans > 'z')
  {
          trans -= 26;
  }*/

  // Return the encrypted letter (cast back to a char)
  return (char)trans;
}