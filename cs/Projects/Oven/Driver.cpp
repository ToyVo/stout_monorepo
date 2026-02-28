#include "Oven.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  Oven oven1;

  cout << oven1.getTemperature() << endl;
  cout << oven1.getCookingStyle() << endl;

  oven1.bake(400, "Fast");

  cout << oven1.getTemperature() << endl;
  cout << oven1.getCookingStyle() << endl;

  system("pause");
  return 0;
};