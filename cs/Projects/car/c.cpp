#include "car.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  Car c(2007, "Pontiac Gran Prix");

  cout << "Make: " << c.getYear() << " " << c.getMake() << endl;

  for (int a = 0; a < 5; a++) {
    c.accelerate();
    cout << "Speed: " << c.getSpeed() << endl;
  }

  for (int a = 0; a < 5; a++) {
    c.brake();
    cout << "Speed: " << c.getSpeed() << endl;
  }

  system("pause");
  return 0;
}