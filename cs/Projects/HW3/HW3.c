#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRMAX 6

struct car {
  char *make;
  char *model;
  int year;
  double cost;
}

main() {
  // int dvd[50][10][24];

  /*int a = 0, b = 0;
  int table[3][4] = {{2, 3}, {7, 8, 9}, {1}};
  for (a = 0; a < 3; a++)
  {
          for (b = 0; b < 4; b++)
          {
                  if (table[a][b]!=0)
                          printf("%3d",table[a][b]);
                  else
                          printf("%3c",'?');
          }
  printf("\n");
  }*/

  int temp[7][24];
  int total = 0;
  float average;
  int i = 0;

  for (i = 0; i < 24; i++) {
    total += temp[2][i];
  }

  average = total / 24;

  printf("%f", average);

  /*struct car forsale = {"Jeep", "Wrangler", 2007, 24000};
  struct car collection[25];

  printf("Make: %s \nModel: %s \nYear: %d \nCost: $%.2f",forsale.make,
  forsale.model, forsale.year, forsale.cost);*/

  getch();
  return;
}
