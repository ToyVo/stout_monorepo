#include <conio.h>
#include <stdio.h>

main() {
  int max, a, b, c;
  a = 44;
  b = 82;
  c = 24;

  if ((a > b) && (a > c)) {
    max = a;
  } else if ((b > a) && (b > c)) {
    max = b;
  } else {
    max = c;
  }

  max = (a > b) ? a : b;
  max = (c > max) ? c : max;

  max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

  printf("%d", max);

  getch();
}