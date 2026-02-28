#ifndef GENE_H
#define GENE_H

#include "Sequence.h"
#include <string>

using namespace std;
// ***********************************************************
//     Gene class header file
// ***********************************************************

class Gene : public Sequence {
public:
  Gene(string s);
  Gene(const Gene &g);            // copy constuctor
  Gene &operator=(const Gene &g); // assignment operator
  ~Gene();
  const int aCount();
  const int cCount();
  const int tCount();
  const int gCount();
};

#endif // GENE_H