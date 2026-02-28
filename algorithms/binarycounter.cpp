#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>

using namespace std;

void increment(int Arr[]) {
  int i = 0;
  int s = Arr.size();
  while (i < Arr.size() && Arr[i] == 1) {
    Arr[i] = 0;
    i++;
  }
  if (i < Arr.size()) {
    Arr[i] = 1;
  }
}

int main() {
  int binaryNumber[8] = {0};
  for (int i = 0; i < 8; i++)
    cout << binaryNumber[i];
  cout << endl;
  increment(binaryNumber);
  for (int i = 0; i < 8; i++)
    cout << binaryNumber[i];
  cout << endl;
}