#include <conio.h>
#include <stdio.h>

void mystery(int a, int b) {
  a = 3;
  b += a;
}

main() {
  /*int c, i, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for (i = 0; i < 10; ++i)
          ndigit[i] = 0;

  while ((c = getchar()) != EOF)
          if (c >= '0' && c <= '9')
                  ++ndigit[c - '0'];
          else if (c == ' ' || c == '\n' || c == '\t')
                  ++nwhite;
          else
                  ++nother;

  printf("digits =");
  for (i = 0; i < 10; ++i)
          printf(" %d", ndigit[i]);
  printf(", white space = %d, other = %d\n", nwhite, nother);*/

  /*int n;

  printf("Enter an integer\n");
  scanf("%d", &n);

  if (n % 2 == 0)
          printf("Even\n");
  else
          printf("Odd\n");*/

  /*int c;

  c = getchar();
  while (c != EOF) {
          putchar(c);
          c = getchar();*/

  /*int c;
  printf("%d", (c = getchar()) != EOF);*/

  /*int counter = 0;
  int c;
  while ((c = getchar()) != EOF)
  {
          counter++;
  }
  printf("%d", counter);

  int count = 1;
  int sum = 0;
  for (count = 1; count <= 3; count++)
  {
          sum += count;
  }
  printf("The sum is = %d\n", sum);
  while (count <= 3)
  {
          sum += count++;
  }
  printf("The sum is = %d\n", sum);*/

  /*int x = 0;
  int y = 1;
  void mystery(int a, int b);

  mystery(x, y);
  printf("%d", x);*/

  /*int x, blanks, tabs, newlines, count;
  x = blanks = tabs = newlines = count = 0;
  char hello[] = "Hello";
  count++;
  while (x != EOF)
  {
          x = hello[count];
          if (x == ' ')
                  ++blanks;
          if (x == '\t')
                  ++tabs;
          if (x == '\n')
                  ++newlines;
          printf("%s",hello[count]);
          count++;
  }
  printf("%s ", hello);
  printf("%d %d %d %d", blanks, tabs, newlines, count);
  getch();*/
}