#include <cstdlib>

#include <iostream>
#include <string>
using namespace std;

#include "Encryption.h"

int main() {
  // Prompt user for the input and output filenames
  string inFileName, outFileName;
  int key;
  cout << "Enter name of file to encrypt (input): ";
  cin >> inFileName;

  cout << "Enter name of file to receive the encrypted text (output): ";
  cin >> outFileName;

  cout << "Enter in the key: " << endl;
  cin >> key;

  // Create a simple encrypter and run the 'encrypt' method
  SimpleEncryption encrypter(inFileName.c_str(), outFileName.c_str());
  encrypter.encrypt(key);

  system("pause");
  return 0;
}
