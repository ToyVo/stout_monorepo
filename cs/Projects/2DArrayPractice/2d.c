#include <conio.h>
#include <stdio.h>

main() {
  int x[3][5] = {{5, 0, 2, -2, 3}, {10, 11, 12, 13, 14}, {20, 30, 40, 50, 60}};
  int i = 0, j = 0;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 5; j++) {
      printf("%3d", x[i][j]);
    }
    printf("\n");
  }

  getch();
}