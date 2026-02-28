#include <stdio.h>
#include <string.h>

int main() {
  char sentenceInput[99];
  char wordInput[20];
  printf("Enter in a sentence\n");
  if (fgets(sentenceInput, sizeof sentenceInput, stdin) == NULL) {
    fprintf(stderr, "Error reading sentenceInput");
  };
  strtok(sentenceInput, "\n");
  printf("Enter in a word to search for\n");
  if (fgets(wordInput, sizeof wordInput, stdin) == NULL) {
    fprintf(stderr, "Error reading sentenceInput");
  };
  strtok(wordInput, "\n");
  printf("Searching %s for %s\n", sentenceInput, wordInput);
  if (strstr(sentenceInput, wordInput)) {
    printf("FOUND\n");
  } else {
    printf("NOT FOUND\n");
  }
  return 0;
}
