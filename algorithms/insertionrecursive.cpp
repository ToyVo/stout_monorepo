void insertion(int *A, int first, int last) {
  for (int i = first; i < last; i++) {
    if (A[last]<A[i]
  }
}

void insertionrecursive(int *A, int first, int last) {
  if (first < last) {
    insertionrecursive(A, first, last - 1);
    key = A[last];
    i = last - 1;
    while (i >= fist && A[i] > key) {
      A[i + 1] = A[i];
      i--;
    }
    A[i + 1] = key;
  }
}