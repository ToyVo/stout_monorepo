#include "DLinkedQueue.h"
#include <iostream>

using namespace std;

int main() {
  DLinkedQueue<int> q1;

  q1.push(1);
  q1.push(2);
  q1.printQueue();
  q1.pop();
  q1.printQueue();
  q1.pop();
  q1.printQueue();

  cout << "q1 size is " << q1.size() << endl;

  try {
    cout << q1.front();
  } catch (underflowError ue) {
    cout << "q1 is empty --> Caught Error for underflow " << endl;
  }

  DLinkedQueue<int> q2;
  // DLinkedQueue<int> q1;
  for (int i = 1; i <= 10; i++)
    q2.push(i);

  q2.printQueue();
  q2.pop();
  q2.printQueue();

  cout << "q2 size is " << q2.size() << " is it empty " << q2.empty() << endl;

  return 0;
}
