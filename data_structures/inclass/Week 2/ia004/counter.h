#include <cstdlib>
#include <iostream>

using namespace std;

class counter {
public:
  counter();
  ~counter();
  int getCount();
  void increaseBy(int x);
  friend bool operator==(const counter lhs, const counter rhs);

private:
  int count;
};