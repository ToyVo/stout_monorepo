#include <stdio.h>
#include <stdlib.h>

int main() {
  int *mp;
  int *ap;

  mp = (int *)malloc(100 * sizeof(int));

  if (mp == NULL) {
    printf("out of memory\n");
    exit(1);
  }

  printf("%10d %p\n", *mp, mp);

  ap = (int *)calloc(100, sizeof(int));

  if (ap == NULL) {
    printf("out of memory\n");
    exit(1);
  }

  printf("%10d %p\n", *ap, ap);

  free(mp);
  free(ap);
  system("pause");
  return 0;
}
