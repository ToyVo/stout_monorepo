// Will take input from a file and read the data from it to be able to then
// print out the ascii art in the terminal
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 100

// A list of any possible errors
void error(int a) {
  switch (a) {
  case 0:
    fprintf(stderr, "Cannot open input file.\n");
    break;
  case 1:
    fprintf(stderr, "character is out of bounds.\n");
    break;
  }
  return;
}

// This function does the actual printing
void print(FILE *artFile) {
  int width = 0, height = 0, row = 0, column = 0, repeat = 0;
  int count = 0, lastrow = 0;
  char discard = ',', symbol = ' ';

  fscanf(artFile, "%d%c%d", &width, &discard, &height);
  printf("Wdith equals: %d Height equals: %d\n", width, height);

  // checks to make sure that all values meant to be scanned are present
  while (fscanf(artFile, "%d%c%d%c%c%c%d", &row, &discard, &column, &discard,
                &symbol, &discard, &repeat) == 7) {
    // checks for if any values are going to go outside of the defined
    // resolution
    if (repeat + column > width + 1 || row > height + 1) {
      error(1);
      return;
    }

    // checks if the row is a new row or not
    if (lastrow < row) {
      count = 0;
      printf("\n");
    }

    // prints spaces
    while (count < column) {
      printf(" ");
      count++;
    }

    // prints the symbol
    while (count < (repeat + column)) {
      printf("%c", symbol);
      count++;
    }

    lastrow = row;
  }
  return;
}

// asks for file name and forwards that to print
main() {
  // grabs the file name
  char FileName[MAXLENGTH];

  FILE *artFile = NULL;

  printf("Enter a file name and extention. Make sure that the file is in the "
         "correct directory:\n");
  printf("This program includes: fly.art, worry.art, heart.art, seuss.art, "
         "impossible.art, cupid.art, box.art, and bigbox.art\n");
  scanf("%s", FileName);

  artFile = fopen(FileName, "r");

  if (artFile == NULL) {
    error(0);
  } else {
    print(artFile);
    fclose(artFile);
  }

  printf("\nEnter any key to exit.");
  getch();
  return;
}