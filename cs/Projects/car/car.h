#include <string>

using namespace std;

class Car {
private:
  int year;
  string make;
  int speed;

public:
  Car();
  Car(int, string);
  int getYear();
  string getMake();
  int getSpeed();
  void accelerate();
  void brake();
};