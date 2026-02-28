#include "Circle.h"
#include <stdlib.h>

using namespace std;

/***************************************
 *               main                  *
 * The main function creates and uses  *
 * 2 Circle objects.                   *
 ***************************************/
int main() {
  // Define a Circle object. Because the setRadius function
  // is never called for it, it will keep the value set
  // by the constructor.
  Circle circle1;

  // Define a second Circle object and set its radius to 2.5
  Circle circle2;
  circle2.setRadius(2.5);

  // Get and display each circle's area
  cout << "The area of circle1 is " << circle1.getArea() << endl;
  cout << "The area of circle2 is " << circle2.getArea() << endl;

  system("pause");
  return 0;
}