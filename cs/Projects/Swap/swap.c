#include <conio.h>
#include <stdio.h>

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
  return;
}

main() {
  int x = 1, y = 2;
  swap(&x, &y);
  printf("%d %d", x, y);
  getch();
}