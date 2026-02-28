#include <iostream>

using namespace std;

#include "Sequence.h"

// ***********************************************************
//     Sequence class implementation
// ***********************************************************

// constructor
Sequence::Sequence(string s) {
  int size = s.size();
  sequence = new char[size];
  for (int i = 0; i < s.size(); i++)
    sequence[i] = s[i];
  length = size;
}

// copy constructor
Sequence::Sequence(const Sequence &seq) {
  length = seq.size();
  char *newSeq = seq.getSequence();
  sequence = new char[length];
  for (int i = 0; i < length; i++)
    sequence[i] = newSeq[i];
}

// destructor
Sequence::~Sequence() {
  // cout<<"in destructor"<<endl;
  delete[] sequence;
}

// member function operator =
Sequence &Sequence::operator=(const Sequence &rhs) {
  length = rhs.size();
  char *newSeq = rhs.getSequence();
  sequence = new char[length];
  for (int i = 0; i < length; i++)
    sequence[i] = newSeq[i];
  delete[] newSeq;
  return *this;
}

// output operator
ostream &operator<<(ostream &ostr, const Sequence &g) {
  char *out = g.getSequence();
  for (int i = 0; i < g.size(); i++) {
    cout << out[i];
    if (i % 40 == 0)
      cout << endl;
  }
  return ostr;
}
// operator ==
bool operator==(const Sequence &lhs, const Sequence &rhs) {
  if (lhs.size() != rhs.size())
    return false;
  else {
    char *lSeq = lhs.getSequence();
    char *rSeq = rhs.getSequence();
    int lastIndex = lhs.size() - 1;
    // test match going forward
    for (int i = 0; i < lhs.size(); i++) {
      if (lSeq[i] != rSeq[i])
        break;
      if (i == lastIndex)
        return true;
    }
    for (int i = 0; i < lhs.size(); i++) {
      if (lSeq[i] != rSeq[lastIndex - i])
        break;
      if (i == lastIndex)
        return true;
    }
    return false;
  }
}

// operator <
bool operator<(const Sequence &lhs, const Sequence &rhs) {
  char *lSeq = lhs.getSequence();
  char *rSeq = rhs.getSequence();

  // index of last element in full sequence
  int lastIndex = rhs.size();
  int subSize = lhs.size();
  if (subSize > rhs.size())
    return false;
  // Check for forward match
  char sub1 = lSeq[0];
  // Check all starting positions where substring fits in string
  for (int i = 0; i <= lastIndex - subSize; i++) {
    // if find first character in subsequence in rhs
    if (rSeq[i] == sub1) {
      if (subSize == 1)
        return true;
      // check rest for matches in rhs starting at i+1
      for (int j = 1; j < subSize;
           j++) { // if not a match, break out and look for next start spot
        // cout<<lSeq[j]<< " equal to "<<rSeq[i+j]<<endl;
        if (lSeq[j] != rSeq[i + j]) {

          break;
        }
        // cout<<"is j:"<<j<<" == "<<(subSize-1)<<endl;
        if (j == subSize - 1)
          return true;
      }
    }
  }
  // Add case for reverse match
  // reverse the shorter sequence and check for match.
  char *lSeq2 = new char[subSize];
  for (int i = 0; i < lhs.size(); i++)
    lSeq2[i] = lSeq[subSize - 1 - i];

  sub1 = lSeq2[0];
  // Check all starting positions where substring fits in string
  for (int i = 0; i <= lastIndex - subSize; i++) {
    // cout<<"testing reverse "<<sub1<<endl;
    // if find first character in subsequence in rhs
    if (rSeq[i] == sub1) {

      // check rest for matches in rhs starting at i+1
      for (int j = 1; j < subSize;
           j++) { // if not a match, break out and look for next start spot
        // cout<<lSeq2[j]<< "equal to "<<rSeq[i+j]<<endl;
        if (lSeq2[j] != rSeq[i + j]) {
          break;
        }
        // cout<<"is j:"<<j<<" == "<<(subSize-1)<<endl;
        if (j == subSize - 1)
          return true;
      }
    }
  }

  return false;
}
