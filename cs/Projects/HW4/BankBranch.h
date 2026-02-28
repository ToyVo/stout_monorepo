#include <String>

using namespace std;

class BankBranch {
private:
  int mBID;
  string mCity;

public:
  BankBranch();
  BankBranch(int, string);
  int getBID();
  string getCity();
  void setBID(int);
  void setCity(string);
  void print();
};