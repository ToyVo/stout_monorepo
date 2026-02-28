#include <array>
#include <iostream>
#include <string>

using namespace std;

template <T> void search(array<T> list, T input) {
  for (int i = 0; i < list.size(); i++) {
    if (input == list[i]) {
      cout << "Found at position: " << i << endl;
    }
  }
}

int main() {
  array<int> numlist = {17, 23, 5, 11, 2, 29, 3};
  int num;
  cout << "Enter a number to search for" << endl;
  cin >> num;
  search(numlist, num);

  system("pause");
  return 1;
}