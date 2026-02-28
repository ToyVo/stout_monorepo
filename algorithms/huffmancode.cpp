// I don't actually know how I'm meant to do this

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

void huffman(int characters[]) {
  int n = 6;
  queue q = c;
  for (int i = 1; i < n; i++) {
    z;
    z.left = x = extract_min(q);
    z.right = y = extract_min(q);
    z.freq = x.freq + y.freq;
    insert(q, z);
  }
  return extract_min(q);
}

int main() {
  char characters[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int frequency[6] = {45, 13, 12, 16, 9, 5};
}