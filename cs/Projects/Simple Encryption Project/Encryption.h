#pragma once

#include <fstream>

// An abstract class providing an 'interface' for file encryption
class Encryption {
protected:
  // The input and output streams
  std::ifstream inFile;
  std::ofstream outFile;

public:
  Encryption(const char *inFileName, const char *outFileName);
  ~Encryption();

  // Retrieve text from 'inFilename' and write it to 'outFileName' encrypted
  void encrypt(int);

  // Encrypt a single letter (must be implemented in child)
  virtual char transform(char ch, int k) const = 0;
};

class SimpleEncryption : public Encryption {
public:
  // Create an encryption object with the given intput and output filenames
  SimpleEncryption(const char *inFileName, const char *outFileName);

  // Overridden from parent, encrypts the one letter
  virtual char transform(char ch, int k) const;
};