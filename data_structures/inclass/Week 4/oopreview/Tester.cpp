#include <cstdlib>
#include <iostream>

#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"

using namespace std;

int main(int argc, char *argv[]) {
  Circle s(8, 2.3, 3.0, 12.0);
  cout << "Circle with color = " << s.getLineColor() << " has area "
       << s.computeArea() << endl
       << endl;

  Rectangle c(0, 0, 5.5, 8.0);
  cout << "Rectangle with color = " << c.getLineColor() << " has area "
       << c.computeArea() << endl
       << endl;

  Shape *s1 = new Circle(2, 3, 4, 5);
  cout << "Circle with color = " << s1->getLineColor() << " has area "
       << s1->computeArea() << endl
       << endl;

  delete s1;

  // 	Shape *r = new Shape(5);

  //     cout << "Shape with color = " << r->getLineColor()
  //           << " has area " << r->computeArea() << endl << endl;

  //     delete r;

  return 0;
}