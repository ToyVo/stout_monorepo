#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

template <class T> class node {
public:
  node(T item, node<T> *nextNode) {
    nodeValue = item;
    next = nextNode;
  }
  T getNodeValue() { return nodeValue; }
  void setNodeValue(T newValue) { nodeValue = newValue; }
  node *getNext() { return next; }
  void setNext(node *newNode) { next = newNode; }

private:
  T nodeValue;
  node<T> *next;
};

template <class T> class LinkedList {
public:
  LinkedList() {
    count = 0;
    headPtr = NULL;
  }
  LinkedList(int nodeCount, node<T> *nextNode) {
    count = nodeCount;
    headPtr = nextNode;
  }
  node<T> *getHeadPtr() { return headPtr; }
  void setHeadPtr(node<T> *newNode) { headPtr = newNode; }
  int getCount() { return count; }
  void modifyCount(int i) { count += i; }

private:
  node<T> *headPtr;
  int count;
};

template <class T> int addNode(LinkedList<T> *pList, int pos, T data) {
  // check errors

  // if LinkedList is empty
  if (pList->getCount() == 0) {
    pList->setHeadPtr(new node<T>(data, NULL));
    pList->modifyCount(1);
    return 1;
  }

  // If placing at index 0
  if (pos == 0) {
    node<T> *newNode = new node<T>(data, pList->getHeadPtr());
    pList->setHeadPtr(newNode);
    pList->modifyCount(1);
    return 1;
  }

  // generic case
  node<T> *newNode = new node<T>(data, NULL);
  node<T> *temp = pList->getHeadPtr();
  for (int i = 1; i < pos; i++) {
    temp = temp->getNext();
  }
  newNode->setNext(temp->getNext());
  temp->setNext(newNode);
  pList->modifyCount(1);
  return 1;
}

template <class T> int removeNode(LinkedList<T> *pList, int pos) {
  // if empty
  if (pList->getCount() == 0) {
    return -1;
  }

  // generic case
  node<T> *temp1 = pList->getHeadPtr();
  node<T> *temp2;
  for (int i = 1; i < pos; i++) {
    temp1 = temp1->getNext();
  }
  temp2 = temp1->getNext();

  temp1->setNext(temp2->getNext());
  delete temp2;

  pList->modifyCount(-1);
  return 1;
}

template <class T> void showNode(LinkedList<T> *pList) {
  // if empty
  if (pList->getCount() == 0) {
    // return;
  }

  // generic case
  node<T> *temp = pList->getHeadPtr();
  while (temp != NULL) {
    cout << temp->getNodeValue() << endl;
    temp = temp->getNext();
  }
}

template <class T> bool isEmpty(LinkedList<T> *pList) {
  if (pList->getCount() == 0) {
    return true;
  } else {
    return false;
  }
}

template <class T> int findPos(LinkedList<T> *pList, T data) {
  // if empty
  if (pList->getCount() == 0) {
    return -1;
  }

  // generic case
  node<T> *temp = pList->getHeadPtr();
  for (int i = 0; i < pList->getCount(); i++) {
    if (temp->getNodeValue() == data) {
      return i;
    }
    temp = temp->getNext();
  }

  // if not found
  return -1;
}

template <class T> void makeEmpty(LinkedList<T> *pList) {
  // if empty
  if (pList->getCount() == 0) {
    return;
  }

  // generic case
  node<T> *temp = pList->getHeadPtr();

  while (temp != NULL) {
    pList->setHeadPtr((pList->getHeadPtr()->getNext()));
    delete temp;
    pList->modifyCount(-1);
    temp = pList->getHeadPtr();
  }
}
