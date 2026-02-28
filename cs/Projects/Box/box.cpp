#include "box.h"

Box::Box(double xAxis, double yAxis, int w, int h) {
  x = xAxis;
  y = yAxis;
  width = w;
  height = h;
}

void Box::move(double xAxis, double yAxis) {
  x = xAxis;
  y = yAxis;
}

int Box::area() { return (width * height); }

double Box::getMinX() { return (x - (width / 2)); }

double Box::getMaxX() { return (x + (width / 2)); }

double Box::getMinY() { return (y - (height / 2)); }

double Box::getMaxY() { return (y + (height / 2)); }

bool Box::intersects(Box b) {
  if (b.getMinX() > getMaxX() || b.getMaxX() < getMinX())
    return false;
  if (b.getMinY() > getMaxY() || b.getMaxY() < getMinY())
    return false;
  return true;
}