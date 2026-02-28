#ifndef DLinkedQueue_CLASS
#define DLinkedQueue_CLASS

#include "d_except.h" // for underflowError exception
#include "d_node.h"   // node class

template <typename T> class DLinkedQueue {
public:
  // Constructor to build linked list
  // Postcondition: headPtr and tailPtr are NULL and qsize is 0
  DLinkedQueue();
  ~DLinkedQueue();

  // insert at the back of the queue
  void push(const T &item);

  // return the value stored at front of queue
  T &front();
  const T &front() const;

  // Remove the first element of the queue
  // Precondition: Queue is not empty (throw underflow)
  // Postcondition: Queue size decremented and front element removed
  void pop();

  // Print the contents of the queue from head to tail
  void printQueue();

  // Print the contents of the queue from tail to head
  void printBackwards();

  int size();
  bool empty();

private:
  // headPtr points to front element of queue
  // tailPtr points to the rear of the queue
  node<T> *headPtr, *tailPtr;

  // number of elements in the DoublyLinkedQueue
  int qsize;
};

// Implement member functions
template <typename T> DLinkedQueue<T>::DLinkedQueue() {
  headPtr = NULL;
  tailPtr = NULL;
  qsize = 0;
}

template <typename T> DLinkedQueue<T>::~DLinkedQueue() {
  node<T> *temp = headPtr;

  while (temp != NULL) {
    headPtr = headPtr->next;
    delete temp;
    qsize--;
    temp = headPtr;
  }
}

template <typename T> void DLinkedQueue<T>::push(const T &item) {
  // if empty
  if (qsize == 0) {
    node<T> *newNode = new node<T>(item);
    tailPtr = newNode;
    headPtr = newNode;
    qsize++;
    return;
  }

  node<T> *newNode = new node<T>(item);
  tailPtr->next = newNode;
  tailPtr = newNode;
  qsize++;
  return;
}

template <typename T> T &DLinkedQueue<T>::front() {
  if (qsize == 0)
    throw underflowError("Empty");
  return headPtr->nodeValue;
}

template <typename T> const T &DLinkedQueue<T>::front() const {
  if (qsize == 0)
    throw underflowError("Empty");
  return headPtr->nodeValue;
}

template <typename T> void DLinkedQueue<T>::pop() {
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

template <typename T> void DLinkedQueue<T>::printQueue() {
  node<T> *temp = headPtr;
  for (int i = 0; i < qsize; i++) {
    cout << temp->nodeValue << endl;
    temp = temp->next;
  }
}

template <typename T> void DLinkedQueue<T>::printBackwards() {
  node<T> *temp = tailPtr;
  for (int i = 0; i < qsize; i++) {
    cout << temp->nodeValue << endl;
    temp = temp->previous;
  }
}

template <typename T> int DLinkedQueue<T>::size() { return qsize; }

template <typename T> bool DLinkedQueue<T>::empty() {
  if (qsize == 0)
    return true;
  return false;
}

#endif // DLinkedQueue_CLASS
