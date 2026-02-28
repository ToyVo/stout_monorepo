#include <conio.h>
#include <stdio.h>

main() {
  float total = 0;
  int count = 0;
  float input[5];

  for (count = 0; count < 4; count++) {
    printf("enter a number: \n");
    scanf("%f", &input[count]);
  }

  for (count = 0; count < 4; count++) {
    total += input[count];
  }

  total = (total / count);
  printf("the average of the numbers is: \n%.2f", total);
  getch();
}