#include "SLinkedQueue.h"

#include <iostream>

using namespace std;

int main() {
  SLinkedQueue<int> queue;

  cout << "\nIf the queue is empty, 1 will be displayed.  If the queue is not "
          "empty, 0 will be displayed."
       << endl;

  cout << queue.empty() << endl;

  queue.push(55);

  cout << "\nAfter pushing an element on, 1 will be displayed if the queue is "
          "empty.  If the queue is not empty, 0 will be displayed."
       << endl;
  cout << queue.empty() << endl;

  queue.push(66);

  cout << "Now the queue, consisting of two elements, will be printed." << endl;
  queue.printQueue();

  for (int i = 1; i <= 10; i++)
    queue.push(i);

  cout << "\nNow the queue will be printed all elements." << endl;
  queue.printQueue();

  cout << "The size of the queue is " << queue.size() << endl;
  cout << "The element at the front of the queue is " << queue.front() << endl;

  cout << "The queue will pop the front element (which is the first element we "
          "pushed "
       << endl;
  queue.pop();

  queue.printQueue();

  cout << "\nNow the queue will be displayed after having its front element "
          "popped off until it is reduced to the size of 5."
       << endl;

  while (queue.size() > 5) {
    queue.pop();
  }
  queue.printQueue();
  cout << endl;

  return 0;
}
