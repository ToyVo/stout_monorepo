#include "Rectangle.h"
#include "Shape.h"
#include <cmath>
#include <iostream>

using namespace std;

Rectangle::Rectangle(double ll_x, double ll_y, double ur_x, double ur_y)
    : Shape(13) {
  ll[0] = ll_x;
  ll[1] = ll_y;
  ur[0] = ur_x;
  ur[1] = ur_y;
  cout << "Rectangle constructor is called" << endl;
}

Rectangle::~Rectangle() {
  cout << this << "--> Rectangle destructor is called ... " << endl;
}

double Rectangle::computeArea() const {
  double length = fabs(ll[0] - ur[0]);
  double height = fabs(ll[1] - ur[1]);

  return length * height;
}
