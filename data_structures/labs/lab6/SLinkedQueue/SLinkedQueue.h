#ifndef LINKEDQUEUE_CLASS
#define LINKEDQUEUE_CLASS

#include "d_except.h" // for underflowError exception
#include "node.h"
#include <iostream>

using namespace std;

template <typename T> class SLinkedQueue {
public:
  // Constructor to build linked list
  // Postcondition: headPtr and tailPtr are NULL and qsize is 0
  SLinkedQueue();

  // Destructor to return memory to the heap
  // Postcondition: Nodes allocated to LinkedQueue are returned to heap
  ~SLinkedQueue();

  // insert at the back of the queue
  // Postcondition: the queue has one more new element qsize +1
  void push(const T &item);

  // Return the value stored at front of queue
  // Precondition: Queue is not empty (throw underflowError)
  // Postcondition:No change to the queue
  T &front();

  const T &front() const;

  // Remove the first element of the queue
  // Precondition: Queue is not empty (throw underflow)
  // Postcondition: Queue size decremented and front element removed and memory
  // for node returned to the heap
  void pop();

  // Print the contents of the queue from head to tail
  void printQueue();

  // Return the number of elements in the queue
  // Precondition: none
  // Postcondition: No change to the queue
  int size();

  // Return the number of elements in the queue
  // Precondition: none
  // Postcondition: No change to the queue
  bool empty();

private:
  // headPtr points to front element of queue
  // tailPtr points to the last element of the queue
  node<T> *headPtr, *tailPtr;

  // number of elements in the SLinkedQueue
  int qsize;
};

template <typename T> SLinkedQueue<T>::SLinkedQueue() {
  qsize = 0;
  headPtr = NULL;
  tailPtr = NULL;
}

template <typename T> SLinkedQueue<T>::~SLinkedQueue() {
  node<T> *temp = headPtr;

  while (temp != NULL) {
    headPtr = headPtr->next;
    delete temp;
    qsize--;
    temp = headPtr;
  }
}

template <typename T> void SLinkedQueue<T>::push(const T &item) {
  // if empty
  if (qsize == 0) {
    node<T> *newNode = new node<T>(item, NULL);
    tailPtr = newNode;
    headPtr = newNode;
    qsize++;
    return;
  }

  node<T> *newNode = new node<T>(item, NULL);
  tailPtr->next = newNode;
  tailPtr = newNode;
  qsize++;
  return;
}

template <typename T> T &SLinkedQueue<T>::front() { return headPtr->nodeValue; }

template <typename T> const T &SLinkedQueue<T>::front() const {
  return headPtr->nodeValue;
}

template <typename T> void SLinkedQueue<T>::pop() {
  // if empty
  if (qsize == 0) {
    return;
  }

  // generic
  node<T> *temp = headPtr;
  headPtr = temp->next;
  if (headPtr == NULL)
    tailPtr = NULL;
  delete temp;
  qsize--;
}

template <typename T> void SLinkedQueue<T>::printQueue() {
  node<T> *temp = headPtr;
  for (int i = 0; i < qsize; i++) {
    cout << temp->nodeValue << endl;
    temp = temp->next;
  }
}

template <typename T> int SLinkedQueue<T>::size() { return qsize; }

template <typename T> bool SLinkedQueue<T>::empty() {
  if (qsize == 0)
    return true;
  return false;
}

#endif // SLINKEDQUEUE_CLASS (Must be last line of code)
