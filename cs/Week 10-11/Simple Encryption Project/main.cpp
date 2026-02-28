#include <cstdlib>

#include <iostream>
#include <string>
using namespace std;

#include "SimpleEncryption.h"

int main() {
  // Prompt user for the input and output filenames
  string inFileName, outFileName;
  cout << "Enter name of file to encrypt (input): ";
  cin >> inFileName;

  cout << "Enter name of file to receive the encrypted text (output): ";
  cin >> outFileName;

  // Create a simple encrypter and run the 'encrypt' method
  SimpleEncryption encrypter(inFileName.c_str(), outFileName.c_str());
  encrypter.encrypt();

  system("pause");
  return 0;
}
