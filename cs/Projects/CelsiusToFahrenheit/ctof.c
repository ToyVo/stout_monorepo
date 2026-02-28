#include <conio.h>
#include <stdio.h>
int main() {
  float celsius, fahrenheit;
  int done;
  printf("Enter a temperature in celsius: ");
  scanf("%f", &celsius);
  fahrenheit = 32.0 + (9.0 / 5.0) * celsius;
  printf("%.2f Degrees in celsius is %.2f degrees in fahrenheit\n", celsius,
         fahrenheit);
  getch();
  return 0;
}