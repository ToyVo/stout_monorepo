#include <array>
#include <iostream>

#define SIZE 6

using namespace std;

void printarr(int arr[]) {
  for (int i = 0; i < SIZE; i++) {
    cout << arr[i];
  }
  cout << endl;
}

int *sortarr(int arr[]) {
  int small = 0;
  for (int i = 1; i < SIZE; i++) {
    for (int j = i; j < SIZE; j++) {
      if (arr[j] < arr[small])
        small = j;
    }
    swap(arr[i], arr[small]);
  }
}

int main() {
  int arr[SIZE] = {2, 4, 6, 3, 5, 1};
  printarr(arr);
  int *a = sortarr(arr);
  printarr(a);
  return 0;
}