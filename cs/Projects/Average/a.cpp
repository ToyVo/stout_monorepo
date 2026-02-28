#include <conio.h>
#include <iostream>

using namespace std;

double findMax(double numset[]) {
  double max = 0;
  for (int i = 0; i < 5; i++)
    if (numset[i] > max)
      max = numset[i];
  return max;
}

double findAve(double numset[]) {
  double average = 0;
  for (int i = 0; i < 5; i++)
    average += numset[i];
  average = average / 5.0;
  return average;
}

int main() {
  double average, max;
  double numset[5];

  cout << "Enter 5 numbers separated by spaces" << endl;

  for (int i = 0; i < 5; i++)
    cin >> numset[i];

  cout << "highest number is: " << findMax(numset) << endl;
  cout << "Average of the numbers is: " << findAve(numset) << endl;

  getch();
  return 0;
}