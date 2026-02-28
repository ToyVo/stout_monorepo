#include <iostream>

using namespace std;

#define SIZE 17

class myData {
public:
  int dayBuy;
  int daySell;
  int maxProfit;
  myData() {
    dayBuy = 0;
    daySell = 0;
    maxProfit = 0;
  }
  myData(int b, int s, int m) {
    dayBuy = b;
    daySell = s;
    maxProfit = m;
  }
};

myData mid_profit(int a[], int first, int middle, int last) {
  int left = -2147483648, right = -2147483648;
  int maxLeft, maxRight;
  int sum = 0;
  for (int i = middle; i > first; i--) {
    sum += a[i];
    if (sum > left) {
      left = sum;
      maxLeft = i;
    }
  }
  sum = 0;
  for (int i = middle + 1; i < last; i++) {
    sum += a[i];
    if (sum > right) {
      right = sum;
      maxRight = i;
    }
  }
  myData temp(maxLeft, maxRight, right + left);
  return temp;
}

myData max_profit(int a[], int first, int last) {
  if (last > first) {
    int middle = (first + last) / 2;
    myData left = max_profit(a, first, middle);
    myData right = max_profit(a, middle + 1, last);
    myData cross = mid_profit(a, first, middle, last);
    if (left.maxProfit > right.maxProfit && left.maxProfit > cross.maxProfit) {
      return left;
    } else if (right.maxProfit > left.maxProfit &&
               right.maxProfit > cross.maxProfit) {
      return right;
    } else {
      return cross;
    }
  }
}

int main() {
  int prices[SIZE] = {100, 113, 110, 85,  105, 102, 86, 63, 81,
                      101, 94,  106, 101, 79,  94,  90, 97};

  myData temp = max_profit(prices, 0, 16);
  cout << "You should buy on day: " << temp.dayBuy << endl;
  cout << "You should sell on day: " << temp.daySell << endl;
  cout << "For a profit of: " << temp.maxProfit << endl;
}