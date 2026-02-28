#include <iostream>
#include <stdlib.h>
using namespace std;

class Shape2D {
protected:
  double locationX, locationY;

public:
  Shape2D(double x, double y) {
    locationX = x;
    locationY = y;
  }
  const void setLocation(double x, double y) {
    locationX = x;
    locationY = y;
  }
  const void getArea() {}
  Shape2D &operator+=(double delta) {
    locationX += delta;
    locationY += delta;
    return *this;
  }
  const void printLocation(ostream &out) {
    out << " at (" << locationX << "," << locationY << ")";
  }
};

class Circle2D : public Shape2D {
private:
  double radius;
  const double PI = 3.1415926535897;

public:
  Circle2D() : Shape2D(0, 0) { radius = 1; }
  Circle2D(double x, double y, double r) : Shape2D(x, y) { radius = r; }
  const double getArea() { return (radius * radius * PI); }
  friend ostream &operator<<(ostream &out, Circle2D &circ) {
    out << "Circle, Radius: " << radius << " Area: " << getarea()
        << " Location " << printLocation();
  }
};

class Rectangle2D : public Shape2D {
private:
  double width, height;

public:
  Rectangle2D() : Shape2D(0, 0) {
    width = 1;
    height = 1;
  }
  Rectangle2D(double x, double y, double w, double h) : Shape2D(x, y) {
    width = w;
    height = h;
  }
  const double getArea() { return (width * height); }
  friend ostream &operator<<(ostream &out, Rectangle2D &rect) {
    out << "Rectangle, " << width << "X" << height << " Area: " << getArea()
        << " Location " << printLocation();
  }
};

int main() {

  system("pause");
  return 0;
}