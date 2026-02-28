#include "Change.h"
#include <iostream>

using namespace std;

Change::Change() {
  setPennies(0);
  setNickels(0);
  setDimes(0);
  setQuarters(0);
}

Change::Change(int p, int n, int d, int q) {
  setPennies(p);
  setNickels(n);
  setDimes(d);
  setQuarters(q);
}

void Change::setPennies(int p) { mPennies = p; }

void Change::setNickels(int n) { mNickels = n; }

void Change::setDimes(int d) { mDimes = d; }

void Change::setQuarters(int q) { mQuarters = q; }

int Change::getPennies() { return mPennies; }

int Change::getNickels() { return mNickels; }

int Change::getDimes() { return mDimes; }

int Change::getQuarters() { return mQuarters; }