#include <cstdlib>
#include <iostream>

#include "Shape.h"

using namespace std;

Shape::Shape(int color) : lineColor(color) {
  cout << "Shape constructor is called" << endl;
}

Shape::~Shape() {
  cout << this << "--> Shape destructor is called ... " << endl;
}

int Shape::getLineColor() const { return lineColor; }

// double Shape::computeArea() const
// {
// 	cerr << "Shape::computeArea() is not implemented" << endl;
// 	exit(-1);
// }
