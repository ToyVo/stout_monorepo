#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape {
public:
  Rectangle(double ll_x, double ll_y, double ur_x, double ur_y);
  virtual ~Rectangle();
  virtual double computeArea() const;

private:
  double ll[2];
  double ur[2];
};

#endif
