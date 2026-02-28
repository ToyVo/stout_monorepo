#include "SimpleEncryption.h"

SimpleEncryption::SimpleEncryption(const char *inFileName,
                                   const char *outFileName)
    : Encryption(inFileName, outFileName) {}

// 'Transform' a letter by shifting it forward by 1
// this is known as a 'shift cipher' and is very easy to hack.
char SimpleEncryption::transform(char ch) const {
  // Add the key value (we use an integer instead of a char for more precision)
  int trans = ch + 1;

  // If it goes past ‘z’ wrap back around to ‘a'
  if (trans > 'z') {
    trans -= 26;
  }

  // Return the encrypted letter (cast back to a char)
  return (char)trans;
}
