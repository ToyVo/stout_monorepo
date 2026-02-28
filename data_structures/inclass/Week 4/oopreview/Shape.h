#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
  Shape(int color);
  virtual ~Shape();
  int getLineColor() const;
  virtual double computeArea() const = 0;

private:
  const int lineColor;
};

#endif
