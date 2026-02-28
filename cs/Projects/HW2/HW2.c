#include <conio.h>
#include <stdio.h>
#include <string.h>
#define STRMAX 6

void reverse(char string1[]) {
  int a = 0;
  char string2[6];
  strcpy(string2, string1);
  for (a = 0; a < 5; a++) {
    string1[a] = string2[4 - a];
  }
  printf("%s", string1);
}

main() {
  char string[STRMAX];
  printf("Enter a 5 letter word:\n");
  scanf("%s", string);
  reverse(string);

  /*int arr[5] = { 5, 4, 3, 2, 1 };
  int *ip = arr;
  int **ipp = &ip;

  printf("%p\n",arr);
  printf("%p\n",ip);
  printf("%p\n",*ip);
  printf("%p\n",*ipp);
  printf("%p\n",ipp);
  printf("%p\n\n",**ipp);

  printf("%d\n", ip[3]);
  printf("%p\n",ip + 2);
  printf("%d\n",*ip + 2);
  printf("%p\n",*ipp);
  printf("%d\n",*(*ipp + 1));*/

  /*int settings[3][5];
  int count = 0, count2 = 0;

  for (count = 0; count <= 2; count++)
  {
          for (count2 = 0; count2 <= 4; count2++)
          {
                  settings[count][count2] = (count*10 + count2);
          }
  }

  for (count = 0; count <= 2; count++)
  {
          for (count2 = 0; count2 <= 4; count2++)
          {
                  printf("%3d ",settings[count][count2]);
          }
          printf("\n");
  }*/

  getch();
  return;
}