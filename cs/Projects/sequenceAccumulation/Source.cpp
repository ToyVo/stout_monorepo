#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T> T accum(vector<T> v) {
  T total = v[0];
  for (int a = 1; a < v.size(); a++) {
    total += v[a];
  }
  return total;
}

int main() {
  vector<int> inta;
  vector<double> doub;
  vector<string> str;
  bool state = true;
  int intin;

  cout << "keep entering numbers then enter 0" << endl;
  while (state) {
    cin >> intin;
    if (intin == 0) {
      state = false;
    } else {
      inta.push_back(intin);
    }
  }

  cout << accum(inta) << endl;
  // cout<<accum(doub)<<endl;
  // cout<<accum(str)<<endl;

  system("pause");
  return 1;
}