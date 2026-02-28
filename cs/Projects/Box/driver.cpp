#include "box.h"
#include <iostream>

using namespace std;

int main() {
  Box b1(1, 10, 6, 8);
  cout << "[b1] Area: " << b1.area() << endl;
  cout << "[b1] Min: [" << b1.getMinX() << "," << b1.getMinY() << "]" << endl;
  cout << "[b1] Max: [" << b1.getMaxX() << "," << b1.getMaxY() << "]" << endl;
  cout << "*******" << endl;

  b1.move(5, 5);
  cout << "[b1] Moved box to location 5,5" << endl;
  cout << "[b1] Min: [" << b1.getMinX() << "," << b1.getMinY() << "]" << endl;
  cout << "[b1] Max: [" << b1.getMaxX() << "," << b1.getMaxY() << "]" << endl;
  cout << "*******" << endl;

  Box b2(3, 3, 4, 4);
  cout << "[b2] Area: " << b2.area() << endl;
  cout << "[b2] Min: [" << b2.getMinX() << "," << b2.getMinY() << "]" << endl;
  cout << "[b2] Max: [" << b2.getMaxX() << "," << b2.getMaxY() << "]" << endl;
  cout << "*******" << endl;

  cout << "Do the boxes overlap? " << b1.intersects(b2) << endl;
  cout << "*******" << endl;

  b2.move(10.5, 8);
  cout << "[b2] Moved box to location 10.5,8" << endl;
  cout << "[b2] Min: [" << b2.getMinX() << "," << b2.getMinY() << "]" << endl;
  cout << "[b2] Max: [" << b2.getMaxX() << "," << b2.getMaxY() << "]" << endl;
  cout << "*******" << endl;

  cout << "Do the boxes overlap? " << b1.intersects(b2) << endl;

  system("pause");
  return 1;
}