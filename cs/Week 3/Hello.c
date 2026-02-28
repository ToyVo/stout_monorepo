
#include <conio.h>
#include <stdio.h>

void sayHello(char s[]) {
  printf("Hello %s", s);
  return;
}

int main() {
  char str[100];

  printf(" Your Name ?");
  scanf("%s", str);

  sayHello(str);

  getch();
  return 0;
}
