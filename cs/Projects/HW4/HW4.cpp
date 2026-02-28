#include "BankBranch.h"
#include "Change.h"
#include "Circle.h"
#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

struct TwoVals {
  int x;
  double y;
};

int main() {
  /*struct TwoVals vals;
  vals.x = 10;
  vals.y = 20;
  cout << vals.x << vals.y << endl;*/

  cout << "Bank" << endl;

  int id;
  string bankCity;

  cout << "Enter a bank ID number: ";
  cin >> id;
  cout << "Enter a city name: ";
  cin >> bankCity;

  BankBranch bank(id, bankCity);
  bank.print();
  bank.setBID(31);
  cout << "Bank ID number is changed to " << bank.getBID() << endl;

  cout << "\nDate" << endl;

  int d;
  string m;
  int y;

  Date today;
  today.print();
  Date tomorrow(26, "August", 1998);
  tomorrow.print();
  Date yesterday;
  cout << "to test enter a number for a date that would be out of bounds: ";
  cin >> d;
  yesterday.setDay(d);
  cout << "test month by entering in a month in a non supported format: ";
  cin >> m;
  yesterday.setMonth(m);
  cout << "there are no restrictions on year, as long as it can fit in an int "
          "type: ";
  cin >> y;
  yesterday.setYear(y);
  yesterday.print();

  system("pause");
  return 0;
}
