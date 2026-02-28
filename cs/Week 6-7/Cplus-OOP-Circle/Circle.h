// This program uses a constructor to initialize a member variable.
#include <iostream>

// Circle class declaration
class Circle {
private:
  double radius;

public: // Member function prototypes
  Circle();
  void setRadius(double);
  double getArea();
};