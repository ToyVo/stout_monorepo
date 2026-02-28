#include <iostream>

using namespace std;

void squareIt(int &num) // refrence
{
  num *= num;
}

void square(int num) // non refrence
{
  num *= num;
}

int sq(int num) // return
{
  return num * num;
}

void main() {
  int var = 5;
  cout << var << endl;

  square(var);
  cout << var << endl;

  squareIt(var);
  cout << var << endl;

  cout << sq(var) << endl;

  system("pause");
  return;
}