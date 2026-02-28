#pragma once

#include "Encryption.h"

// The subclass simply overides the virtual transformation function
class SimpleEncryption : public Encryption {
public:
  // Create an encryption object with the given intput and output filenames
  SimpleEncryption(const char *inFileName, const char *outFileName);

  // Overridden from parent, encrypts the one letter
  virtual char transform(char ch) const;
};
