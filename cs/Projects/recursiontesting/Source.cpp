#include <iostream>

using namespace std;

void message(int n) {
  if (n > 0) {
    static int count = 0;
    cout << "This is a recursive function. " << ++count << endl;
    message(--n);
  }
}

long long factorial(long long num) {
  if (num == 0)
    return 1;
  else
    return num * factorial(num - 1);
}

int sumation(int num) {
  if (num <= 0)
    return num;
  return num + sumation(num - 1);
}

long long fib(long long num) {
  if (num == 1 || num <= 0)
    return num;
  else
    return fib(num - 1) + fib(num - 2);
}

int main() {
  message(5);
  cout << factorial(25) << endl;
  cout << sumation(20) << endl;
  cout << fib(10) << endl;
  system("pause");
  return 1;
}