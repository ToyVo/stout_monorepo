#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

vector<int> greedyAcitvity(int startTime[], int finishTime[]) {
  vector<int> solution;
  int endTime = -9999;
  for (int i = 0; i < 11; i++) {
    if (startTime[i] > endTime) {
      solution.push_back(i);
      endTime = finishTime[i];
    }
  }
  return solution;
}

int main() {
  int start[11] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
  int finish[11] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

  vector<int> v = greedyAcitvity(start, finish);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}
