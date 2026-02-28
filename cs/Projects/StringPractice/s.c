#include <conio.h>
#include <stdio.h>
#include <string.h>
#define MAXLENGTH 100

int main() {
  char string1[MAXLENGTH];
  char string2[MAXLENGTH];

  strcpy(string1, "Hello World!");
  strcpy(string2, string1);

  printf("string1: %s\nstring2: %s\n", string1, string2);

  strcpy(string1, "ABC ");
  strcpy(string2, "DEF ");

  strcat(string1, string2);
  strcat(string1, "XYZ ");

  printf("string1: %s\nstring2: %s\n", string1, string2);

  printf("Enter String1: ");
  scanf("%s", string1);
  printf("Enter String2: ");
  scanf("%s", string2);

  if (strcmp(string1, string2) < 0) {
    printf("%s > %s\n", string1, string2);
  } else if (strcmp(string1, string2) > 0) {
    printf("%s < %s\n", string1, string2);
  } else {
    printf("%s == %s\n", string1, string2);
  }

  printf("The length of string1 = %d", strlen(string1));

  getch();
  return 0;
}
