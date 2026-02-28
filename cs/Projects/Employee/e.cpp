#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  Employee susan("Susan Meyers", 47899, "Accounting", "Vice President");
  Employee mark("Mark Jones", 39119, "IT", "Porgrammer");
  Employee joy("Joy Rogers", 81774, "Manufacturing", "Engineer");
  susan.print();
  mark.print();
  joy.print();
  system("pause");
  return 0;
}