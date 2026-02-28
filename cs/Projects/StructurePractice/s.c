#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  int id;
  char name[20];
  float percentage;
}

main() {
  struct student record;

  record.id = 1;
  strcpy(record.name, "Robert");
  record.percentage = 86.5;

  printf("ID is: %d\n", record.id);
  printf("Name is: %s\n", record.name);
  printf("Percentage is: %.2f\n", record.percentage);

  getch();
  return;
}