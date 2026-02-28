#include "ShapeAnimator.h"
#include <stdlib.h>

int main() {
  // Create a tent and a box
  Tent tent(20, 10, 13);
  Box box(5, 10, 4, 7);

  // Draw the tent and the box
  tent.draw();
  box.draw();

  // Set direction of motion for the two shapes
  tent.setDirection(-1, 0); // Tent moves straight up
  box.setDirection(0, 1);   // Box moves horizontally to the right

  // Simultaneously move the tent and the box
  for (int k = 0; k < 12; k++) {
    Sleep(75);
    tent.move();
    box.move();
  }
  box.move();
  tent.move();

  // Move the box farther to the right
  for (int k = 0; k < 48; k++) {
    Sleep(75);
    box.move();
  }

  // Create a complex shape composed of the tent and the box
  Shape *myShapes[] = {&tent, &box};
  ComplexShape cS(myShapes, 2);

  // Set directions for the two shapes
  tent.setDirection(1, 0);
  box.setDirection(0, -1);

  // Move the complex shape: this moves both the tent and the box
  for (int k = 0; k < 12; k++) {
    Sleep(75);
    cS.move();
  }
  // Continue moving the box by itself
  for (int k = 0; k < 36; k++) {
    Sleep(75);
    box.move();
  }

  system("pause");
  return 0;
}