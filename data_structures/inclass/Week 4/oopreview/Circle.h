#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
public:
  Circle(int color, double center_x, double center_y, double i_radius);
  virtual ~Circle();
  virtual double computeArea() const;

private:
  double center[2];
  double radius;
};

#endif
