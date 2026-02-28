#include <conio.h>
#include <stdio.h>
#include <string.h>

/* definition of local function n_char */
int n_char(char string[]) {
  /* local variable in this function   */
  int n;
  /* strlen(a) returns the length of   */
  /* string a                          */
  /* defined via the string.h header   */
  n = strlen(string);
  if (n > 50)
    printf("String is longer than 50 characters\n");

  /* return the value of integer n  */
  return n;
}

int main() {
  int n;
  char string[50];
  /* strcpy(a,b) copies string b into a */
  /* defined via the stdio.h header     */
  strcpy(string, "Hello World");

  /* call own function */
  n = n_char(string);
  printf("Length of string = %d\n", n);

  getch();

  return 0;
}
