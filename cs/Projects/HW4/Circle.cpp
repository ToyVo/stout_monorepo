#include "Circle.h"
#include <iostream>

Circle::Circle() {
  setCenter(0, 0);
  setRadius(0);
}

void Circle::setCenter(double x, double y) {
  mCenterX = x;
  mCenterY = y;
}

void Circle::setRadius(double r) { mRadius = r; }