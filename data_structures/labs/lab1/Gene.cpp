// ***********************************************************
//     Gene class implementation
// ***********************************************************
#include "Gene.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Gene::Gene(string s) : Sequence(s) {}

Gene::Gene(const Gene &g) : Sequence(g) {}

Gene &Gene::operator=(const Gene &g) {
  Sequence::operator=(g);
  return *this;
}

Gene::~Gene() {
  // Sequence::~Sequence()
}

const int Gene::aCount() {
  char *gene = getSequence();
  int count = 0;
  for (int i = 0; i < size(); i++) {
    if (gene[i] == 'a')
      count++;
  }
  return count;
}

const int Gene::cCount() {
  char *gene = getSequence();
  int count = 0;
  for (int i = 0; i < size(); i++) {
    if (gene[i] == 'c')
      count++;
  }
  return count;
}

const int Gene::tCount() {
  char *gene = getSequence();
  int count = 0;
  for (int i = 0; i < size(); i++) {
    if (gene[i] == 't')
      count++;
  }
  return count;
}

const int Gene::gCount() {
  char *gene = getSequence();
  int count = 0;
  for (int i = 0; i < size(); i++) {
    if (gene[i] == 'g')
      count++;
  }
  return count;
}