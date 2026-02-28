#include "BankBranch.h"
#include <iostream>
#include <string>

using namespace std;

BankBranch::BankBranch() {
  setBID(0);
  setCity("NULL");
}

BankBranch::BankBranch(int b, string s) {
  setBID(b);
  setCity(s);
}

int BankBranch::getBID() { return mBID; }

string BankBranch::getCity() { return mCity; }

void BankBranch::setBID(int b) { mBID = b; }

void BankBranch::setCity(string s) { mCity = s; }

void BankBranch::print() {
  cout << "Bank Branch: " << mBID << ", " << mCity << endl;
}