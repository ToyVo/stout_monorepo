#include <conio.h>
#include <stdio.h>

main() {
  /*char c = 'A';
  char *cptr = NULL;
  cptr = &c;

  printf("%c \n", c);
  printf("%p \n", &c);

  printf("%p \n", cptr);
  printf("%C \n", *cptr);

  *cptr = 'S';

  printf("%C \n", *cptr);
  printf("%c \n", c);*/

  /*int I = 5;
  int *ptr = NULL;

  ptr = &I;

  printf("I = %d \n", I);
  printf("Address of I = %p \n", &I);
  printf("ptr = %p \n ", ptr);
  printf("*ptr = %p \n ", *ptr);

  printf("*&ptr = %p \n", *&ptr);
  printf("&*ptr = %p \n ", &*ptr);
  printf("ptr = %p \n", ptr);
  printf("*ptr = %p", *ptr);*/

  /*int *p, i;

  int val[7] = {11, 22, 33, 44, 55, 66, 77};

  p = &val[0];

  for(i = 0; i < 7; i++)
          printf("val[%d]: value is %d and adress is %u\n", i, *(p+i), (p+i));

  for(i = 0; i < 7; i++)
           *(p+i) += 1;

  for(i = 0; i < 7; i++)
          printf("val[%d]: value is %d and adress is %u\n", i, *(p+i), (p+i));*/

  int arr[5] = {5, 4, 3, 2, 1};
  int *ip = &arr[0];
  int **ipp = &ip;

  printf("%d\n", arr);
  printf("%d\n", *ip + 2);
  printf("%d\n", ipp);

  printf("%d\n", (*ipp)[3]);
  printf("%d\n", ip + 2);
  printf("%d\n", *ip + 2);
  printf("%d\n", *ipp);
  printf("%d\n", *(*ipp + 1));

  getch();
  return;
}