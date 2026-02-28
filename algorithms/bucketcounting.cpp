#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

#define SIZE 15

void bucketSort() {
  float list[SIZE];
  float sorted[SIZE];
  vector<float> bucket[SIZE];

  // generate random numbers
  for (int i = 0; i < SIZE; i++) {
    list[i] = (float)rand() / (float)RAND_MAX;
  }

  // push elements into vectors
  for (int i = 0; i < SIZE; i++) {
    int index = SIZE * list[i];
    bucket[index].push_back(list[i]);
  }

  // sort
  for (int i = 0; i < SIZE; i++) {
    sort(bucket[i].begin(), bucket[i].end());
  }

  // put into sorted list
  int index = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < bucket[i].size(); j++) {
      sorted[index++] = bucket[i][j];
    }
  }

  // print out numbers
  cout << "Bucket Sort" << endl;
  cout << "Before sorting" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << list[i] << " ";
  }
  cout << endl;
  cout << "After sorting" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << sorted[i] << " ";
  }
  cout << endl;

  return;
}

void countingSort() {
  int list[SIZE];
  int counting[101] = {0};
  int sorted[SIZE];

  // generating random numbers
  for (int i = 0; i < SIZE; i++) {
    list[i] = rand() % 101;
  }

  // adding number of times each number occurs into counting
  for (int i = 0; i < SIZE; i++) {
    counting[list[i]]++;
  }
  // counting at i will contain number of elements <= i
  for (int i = 1; i < 101; i++) {
    counting[i] = counting[i] + counting[i - 1];
  }
  // copying numbers into a sorted list
  for (int i = SIZE - 1; i >= 0; i--) {
    sorted[counting[list[i]]] = list[i];
    counting[list[i]]--;
  }

  // print out lists
  cout << "counting sort" << endl;
  cout << "unsorted" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << list[i] << " ";
  }
  cout << endl;
  cout << "sorted" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << sorted[i] << " ";
  }
  cout << endl;

  return;
}

int main() {
  countingSort();
  bucketSort();
  return 0;
}