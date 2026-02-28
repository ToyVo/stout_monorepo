#pragma once

#include <fstream>

// An abstract class providing an 'interface' for file encryption
class Encryption {
public:
  Encryption(const char *inFileName, const char *outFileName);
  ~Encryption();

  // Retrieve text from 'inFilename' and write it to 'outFileName' encrypted
  void encrypt();

  // Encrypt a single letter (must be implemented in child)
  virtual char transform(char ch) const = 0;

protected:
  // The input and output streams
  std::ifstream inFile;
  std::ofstream outFile;
};
