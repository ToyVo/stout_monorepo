#include <iostream>

using namespace std;

int main() {
  int arr[6];
  arr = [ 2, 4, 6, 5, 3, 1 ];
  print(arr);
  arr = sort(arr);
  print(arr);

  return;
}

int[] sort(int arr[]) {
  int small = 0;
  for (int i = 0; i < arr.length(); i++) {
    for (int j = i; j < arr.length(); j++) {
      if (arr[j] < arr[small])
        small = j;
    }
    swap(i, small);
  }
  return;
}

void print(int[] arr) {
  for (int i = 0; i < arr.length(); i++) {
    cout << arr[i];
  }
}