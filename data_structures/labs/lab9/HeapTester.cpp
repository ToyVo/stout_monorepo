#include "Heap.h"
#include "d_random.h" //Provides random number generator
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <iostream>   // Provides cin, cout

using namespace std; // Use C++ Standard namespace

// Elements in each array.
const int ARR_SIZE = 10;

// Main method to test implementation of heap
int main() {
  // Practice with the heap
  Heap<int> h;

  for (int i = 0; i < ARR_SIZE; i++) {
    h.enqueue(i);
    cout << "\nJust enqueued " << i << endl;
    h.printHeap();
  }
  cout << "\n--> Heap size: " << h.size() << endl;

  for (int i = 0; i < ARR_SIZE; i++) {
    h.dequeue();
    cout << "\nAfter dequeue" << endl;
    h.printHeap();
  }
  cout << "\n--> Heap size: " << h.size() << endl;

  // (1) enqueue( ) for 1, 3, 8, 13, 4, 10, 6
  h.enqueue(1);
  h.enqueue(3);
  h.enqueue(8);
  h.enqueue(13);
  h.enqueue(4);
  h.enqueue(10);
  h.enqueue(6);
  // (2) printHeap( )
  h.printHeap();
  // (3) dequeue() and printHeap()
  h.dequeue();
  h.printHeap();
  // (4) dequeue() and printHeap()
  h.dequeue();
  h.printHeap();

  return EXIT_SUCCESS;
}
