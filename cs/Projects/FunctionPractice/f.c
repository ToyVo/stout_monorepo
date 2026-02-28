#include <conio.h>
#include <stdio.h>

void inc(int i) {
  i++;
  printf("%d", i);
}

main() {
  int i = 0;
  printf("enter a number: ");
  scanf("%d", &i);
  inc(i);
  getch();
}