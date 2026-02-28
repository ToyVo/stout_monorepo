#include "Inventory.h"
#include <iostream>

using namespace std;

int main() {
  int itemNumber, quantity;
  double cost;

  cout << "Enter the item number, quantity and cost for item1 separated by "
          "spaces"
       << endl;
  cin >> itemNumber >> quantity >> cost;
  Inventory item1(itemNumber, quantity, cost);
  item1.getTotalCost();

  system("pause");
  return 0;
}