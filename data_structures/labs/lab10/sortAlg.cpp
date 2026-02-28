#include <cstdlib>  // Provides EXIT_SUCCESS
#include <ctime>    // Provides clock_gettime function
#include <iostream> // Provides cin, cout
#include <string.h>
#include <vector>

using namespace std;

// Data type for storing a sorting algorithm name and its running time
struct TestMSG {
  string alg;
  double time;
  TestMSG(string algName, double t) {
    alg = algName;
    time = t;
  }
};

const int SIZE = 20;     // data size. Do not hard code sizes.
int temp[SIZE];          // it is used in merge() as temporary storage
int testData[SIZE];      // keep the same data for algorithm comparisions
vector<TestMSG> results; // store testing results

// swap two values stored at index positions x and y of the array
static void swap(int list[], int x, int y) {
  int temp = list[x];
  list[x] = list[y];
  list[y] = temp;
}

// print all values stored in the array
static void print(int list[]) {
  for (int i = 0; i < SIZE; i++) {
    if (i % 20 == 0 && i != 0)
      cout << endl;
    cout << list[i] << " ";
  }
  cout << endl;
}

// generate random numbers and stored in an array testData[]
void generateTestData() {
  // random number generator
  srand(time(NULL));

  for (int i = 0; i < SIZE; i++)
    // uncomment the next line if you want to have data in order
    // list[i] = SIZE - i;
    testData[i] = rand() % (SIZE * 5) + 1; // then comment this line
}

// convert a time (secs and nano secs) to milliseconds
static double TimeSpecToMilliSeconds(struct timespec *ts) {
  return (double)ts->tv_sec * 1000 + (double)ts->tv_nsec / 1000000.0;
}

void bubbleSort(int list[], int n) {
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (list[j] > list[j + 1])
        swap(list, j, j + 1);
    }
  }
}

void insertionSort(int list[], int n) {
  int key, j;
  for (int i = 1; i < n; i++) {
    key = list[i];
    for (j = i - 1; j >= 0 && list[j] > key; j--)
      list[j + 1] = list[j];
    list[j + 1] = key;
  }
}

void selectionSort(int list[], int n) {
  int smallest;

  for (int i = 0; i < n - 1; i++) {
    smallest = i;
    for (int j = i + 1; j < n; j++) {
      if (list[j] < list[smallest])
        smallest = j;
    }
    swap(list, i, smallest);
  }
}

// (7) merge two groups that have sorted values (see pseudocode)
void merge(int list[], int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int index = left;

  int sorted[SIZE];
  while (i <= mid && j <= right) {
    if (list[i] <= list[j]) {
      sorted[index] = list[i];
      index++;
      i++;
    } else {
      sorted[index] = list[j];
      index++;
      j++;
    }
  }
  // Copy the all remain elements in list to sorted[ ]
  while (i <= mid) {
    sorted[index] = list[i];
    i++;
    index++;
  }
  while (j <= right) {
    sorted[index] = list[j];
    j++;
    index++;
  }
  // Copy the sorted array to list
  for (int l = left; l <= right; l++)
    list[l] = sorted[l];
}

// (6) a recursive function of merge sort
// divide and conquer algorithm (see pseudocode)
void mergeSort(int list[], int left, int right) {
  int mid;
  if (left < right) {
    mid = (left + right) / 2;
    mergeSort(list, left, mid);
    mergeSort(list, mid + 1, right);
    merge(list, left, mid, right);
  }
}

// (9) set the value stored at low (left most index) to pivot
// partition a range of the values into two parts
// return the pivot index (see pseudocode)
int partition(int list[], int low, int high) {
  int pivotIndex = low;
  int pivot = list[low];
  int i = low;
  int j = high;

  while (i < j) {
    while (i < j && pivot <= list[j]) {
      j--;
    }
    while (i < j && list[i] <= pivot) {
      i++;
    }
    if (i < j) {
      swap(list, i, j);
    }
  }
  swap(list, pivotIndex, j);
  return j;
}

// (8) a recursive function of quick sort
// divide and conquer algorithm (see pseudocode)
void quickSort(int list[], int left, int right) {
  if (left >= right)
    return;

  int p = partition(list, left, right);
  quickSort(list, left, p - 1);
  quickSort(list, p + 1, right);
}

void testBubbleSort() {
  // varaibles to get clocktime
  struct timespec start, end;
  double elapsedSeconds;
  int list[SIZE];

  for (int i = 0; i < SIZE; i++)
    list[i] = testData[i];

  cout << "Bubble Sort" << endl;
  cout << "before sorting: " << endl;
  print(list);

  // get elaspsed time for sorting in ms
  clock_gettime(CLOCK_MONOTONIC, &start);

  bubbleSort(list, SIZE);

  clock_gettime(CLOCK_MONOTONIC, &end);
  elapsedSeconds =
      TimeSpecToMilliSeconds(&end) - TimeSpecToMilliSeconds(&start);

  cout << "after sorting: " << endl;
  print(list);

  TestMSG msg("Bubble Sort", elapsedSeconds);
  results.push_back(msg);
}

// (1) The framework of the implmentation of these four utility functions
// are the same as testBubbleSort()
// Copy the codes from testBubbleSort() and modify them
void testSelectionSort() {
  struct timespec start, end;
  double elapsedSeconds;
  int list[SIZE];

  for (int i = 0; i < SIZE; i++)
    list[i] = testData[i];

  cout << "Selection Sort" << endl;
  cout << "before sorting: " << endl;
  print(list);

  // get elaspsed time for sorting in ms
  clock_gettime(CLOCK_MONOTONIC, &start);

  selectionSort(list, SIZE);

  clock_gettime(CLOCK_MONOTONIC, &end);
  elapsedSeconds =
      TimeSpecToMilliSeconds(&end) - TimeSpecToMilliSeconds(&start);

  cout << "after sorting: " << endl;
  print(list);

  TestMSG msg("Selection Sort", elapsedSeconds);
  results.push_back(msg);
}

void testInsertionSort() {
  struct timespec start, end;
  double elapsedSeconds;
  int list[SIZE];

  for (int i = 0; i < SIZE; i++)
    list[i] = testData[i];

  cout << "Insertion Sort" << endl;
  cout << "before sorting: " << endl;
  print(list);

  // get elaspsed time for sorting in ms
  clock_gettime(CLOCK_MONOTONIC, &start);

  insertionSort(list, SIZE);

  clock_gettime(CLOCK_MONOTONIC, &end);
  elapsedSeconds =
      TimeSpecToMilliSeconds(&end) - TimeSpecToMilliSeconds(&start);

  cout << "after sorting: " << endl;
  print(list);

  TestMSG msg("Insertion Sort", elapsedSeconds);
  results.push_back(msg);
}

void testMergeSort() {
  struct timespec start, end;
  double elapsedSeconds;
  int list[SIZE];

  for (int i = 0; i < SIZE; i++)
    list[i] = testData[i];

  cout << "Merge Sort" << endl;
  cout << "before sorting: " << endl;
  print(list);

  // get elaspsed time for sorting in ms
  clock_gettime(CLOCK_MONOTONIC, &start);

  mergeSort(list, 0, (SIZE - 1));

  clock_gettime(CLOCK_MONOTONIC, &end);
  elapsedSeconds =
      TimeSpecToMilliSeconds(&end) - TimeSpecToMilliSeconds(&start);

  cout << "after sorting: " << endl;
  print(list);

  TestMSG msg("Merge Sort", elapsedSeconds);
  results.push_back(msg);
}

void testQuickSort() {
  struct timespec start, end;
  double elapsedSeconds;
  int list[SIZE];

  for (int i = 0; i < SIZE; i++)
    list[i] = testData[i];

  cout << "Quick Sort" << endl;
  cout << "before sorting: " << endl;
  print(list);

  // get elaspsed time for sorting in ms
  clock_gettime(CLOCK_MONOTONIC, &start);

  quickSort(list, 0, (SIZE - 1));

  clock_gettime(CLOCK_MONOTONIC, &end);
  elapsedSeconds =
      TimeSpecToMilliSeconds(&end) - TimeSpecToMilliSeconds(&start);

  cout << "after sorting: " << endl;
  print(list);

  TestMSG msg("Quick Sort", elapsedSeconds);
  results.push_back(msg);
}

int main() {

  generateTestData();

  testBubbleSort();

  // (2) call testSelectionSort()
  testSelectionSort();

  // (3) call testInsertionSort()
  testInsertionSort();

  // (4) call testMergeSort()
  testMergeSort();

  // (5) call testQuickSort()
  testQuickSort();

  // (10) Test the algorithms with data size 20 as initialized
  // increase the data size (static variable SIZE) and check the results
  for (int i = 0; i < results.size(); i++)
    cout << (results.at(i)).alg << ": " << (results.at(i)).time << " ms"
         << endl;

  return 0;
}
