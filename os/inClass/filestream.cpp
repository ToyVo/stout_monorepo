#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
  std::ofstream outFile;
  outFile.open("myRandomNumbers.txt");

  std::srand(time(NULL));

  int len = random() % 1001 + 1000;

  for (int i = 0; i < len; ++i) {
    outFile << random() % 51 + 50 << endl;
  }

  outFile.close();
  cout << "file has been created" << endl;

  vector<int> data;
  std::ifstream inFile;
  inFile.open("myRandomNumbers.txt");

  if (inFile.fail()) {
    cout << "Failed to open file" << endl;
    return 1;
  }

  int tempNo;
  while (inFile >> tempNo) {
    data.push_back(tempNo);
  }

  std::sort(data.begin(), data.end());

  for (int i : data) {
    cout << i << endl;
  }

  return 0;
}