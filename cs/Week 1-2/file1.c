#include <conio.h>
#include <stdio.h>
#define MAXLEN 100

int main() {
  FILE *inputfile = NULL;
  FILE *outfile = NULL;

  char name[MAXLEN];
  int count;
  float mark;

  inputfile = fopen("Names.txt", "r");
  outfile = fopen("outName.txt", "w");

  if (inputfile == NULL) {
    printf("Unable to open input file.\n");
    return 1;
  }

  /* Read in each name, and keep count how
     many names there are in the file. */

  count = 0;
  while (fscanf(inputfile, "%s", name) == 1) {
    count++;

    printf("Enter mark for %s: ", name);
    scanf("%f", &mark);

    if (fprintf(outfile, " %d. %s %f\n", count, name, mark) <= 0) {
      printf("Error writing to output file.\n");
      return 1;
    }
  }

  fclose(inputfile);
  fclose(outfile);

  getch();
  return 0;
}
