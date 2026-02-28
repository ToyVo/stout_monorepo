#include "Rectangle.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

/*************************************************************
 *                            main                           *
 *************************************************************/
int main() {
  Rectangle box; // Declare a Rectangle object
  double boxLength, boxWidth;

  // Get box length and width
  cout << "This program will calculate the area of a rectangle.\n";
  cout << "What is the length? ";
  cin >> boxLength;
  cout << "What is the width? ";
  cin >> boxWidth;

  // Call member functions to set box dimensions
  box.setLength(boxLength);
  box.setWidth(boxWidth);

  // Call member functions to get box information to display
  cout << "\nHere is the rectangle's data:\n";
  cout << "Length: " << box.getLength() << endl;
  cout << "Width : " << box.getWidth() << endl;
  cout << "Area  : " << box.getArea() << endl;

  system("pause");
  return 0;
}
