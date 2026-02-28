#include "Circle.h"
#include <cmath>
#include <iostream>

using namespace std;

Circle::Circle(int color, double center_x, double center_y, double i_radius)
    : Shape(color) {
  radius = i_radius;
  center[0] = center_x;
  center[1] = center_y;
  cout << "Circle constructor is called" << endl;
}

Circle::~Circle() {
  cout << this << "--> Circle destructor is called ... " << endl;
}

double Circle::computeArea() const { return M_PI * radius * radius; }
