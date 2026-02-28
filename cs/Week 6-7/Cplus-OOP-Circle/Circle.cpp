#include "Circle.h"
#include <cmath>

// Circle member function implementation section

/********************************************
 *             Circle::Circle               *
 * This is the constructor. It initializes  *
 * the radius class member variable.        *
 ********************************************/
Circle::Circle() { radius = 1.0; }

/********************************************
 *             Circle::setRadius            *
 * This function validates the value passed *
 * to it before assigning it to the radius  *
 * member variable.                         *
 ********************************************/
void Circle::setRadius(double r) {
  if (r >= 0.0)
    radius = r;
  // else leave it set to its previous value
}

/**********************************************
 *               Circle::getArea              *
 * This function calculates and returns the   *
 * Circle object's area. It does not need any *
 * parameters because it can directly access  *
 * the member variable radius.                *
 **********************************************/
double Circle::getArea() { return 3.14 * pow(radius, 2); }