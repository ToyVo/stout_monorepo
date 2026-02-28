#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>
using namespace std;

class Sequence {
public:
  // constructor accepting a string and converted to a character array
  // initializes sequence and size data members.
  Sequence(string s);

  // copy constructor accepting a string and converted to a character array
  // initializes sequence and size data members.
  Sequence(const Sequence &seq);

  // destructor
  ~Sequence();

  // member functions
  Sequence &operator=(const Sequence &rhs);
  int size() const { return length; }
  char *getSequence() const { return sequence; }
  void set(int index, char c) { sequence[index] = c; }

  friend ostream &operator<<(ostream &ostr, const Sequence &g);
  friend bool operator==(const Sequence &lhs, const Sequence &rhs);
  friend bool operator<(const Sequence &lhs, const Sequence &rhs);

private:
  int length;     // Number of characters in the Sequence
  char *sequence; // character array holding the sequence
};
#endif // SEQUENCE_H
