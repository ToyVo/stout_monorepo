#include "Inventory.h"
#include <iostream>

using namespace std;

Inventory::Inventory() {
  setItemNumber(0);
  setQuantity(0);
  setCost(0);
}

Inventory::Inventory(int i, int q, double c) {
  setItemNumber(i);
  setQuantity(q);
  setCost(c);
}

void Inventory::setItemNumber(int i) {
  if (i > 0) {
    itemNumber = i;
  } else {
    cout << "Item number must be greater than 0 \nPlease enter in a new item "
            "number: ";
    cin >> i;
    setItemNumber(i);
  }
}

void Inventory::setQuantity(int q) {
  if (q > 0)
    quantity = q;
  else {
    cout << "Quantity must be greater than 0 \nPlease enter in a new value: ";
    cin >> q;
    setItemNumber(q);
  }
}

void Inventory::setCost(double c) {
  if (c > 0)
    cost = c;
  else {
    cout << "Cost must be greater than 0 \nPlease enter in a new value: ";
    cin >> c;
    setItemNumber(c);
  }
}

int Inventory::getItemNumber() { return itemNumber; }

int Inventory::getQuantity() { return quantity; }

double Inventory::getCost() { return cost; }

void Inventory::getTotalCost() {
  cout << "Total cost for " << quantity << " of item number " << itemNumber
       << " at $" << cost << " per item is $" << (cost * quantity) << endl;
}