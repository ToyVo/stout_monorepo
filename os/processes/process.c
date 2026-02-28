#include <stdlib.h>

int nprimes;
int *prime;
int current = 2;
int i;

int main(int argc, char *argv[]) {
  nprimes = atoi(argv[1]);
  prime = (int *)malloc(nprimes * sizeof(int));
  prime[0] = current;
  for (i = 1; i < nprimes; i++) {
    int j;
  NewCandidate:
    current++;
    for (j = 0; prime[j] * prime[j] <= current; j++) {
      if (current % prime[j] == 0) {
        goto NewCandidate;
      }
      prime[i] = current;
    }
  }
  return (0);
}