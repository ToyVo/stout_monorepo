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
  T nodeValue;
  node<T> *next;
};

template <class T> class LinkedList {
public:
  LinkedList(int nodeCount, node<T> *nextNode) {
    count = nodeCount;
    headPtr = nextNode;
  }
  node<T> *headPtr;
  int count;
};

template <class T> int addNode(LinkedList<T> *pList, int pos, T data);
template <class T> int removeNode(LinkedList<T> *pList, int pos);
template <class T> void showNode(LinkedList<T> *pList);
template <class T> bool isEmpty(LinkedList<T> *pList);
template <class T> int findPos(LinkedList<T> *pList, T data);
template <class T> void makeEmpty(LinkedList<T> *pList);

int main() {
  int pos;
  LinkedList<int> *list = new LinkedList<int>(0, NULL);

  cout << "list should be empty" << endl;
  showNode(list);

  for (int i = 0; i < 5; i++)
    addNode(list, i, i * 10);

  cout << "List should contain 5 nodes from 0 to 40" << endl;
  showNode(list);

  addNode(list, 0, 50);

  cout << "list should contain 6 nodes starting at 50 ending at 40" << endl;
  showNode(list);

  pos = findPos(list, 30);
  cout << "\nThe location of node with data '30': " << pos << endl << endl;

  removeNode(list, 2);
  cout << "After delete the 3rd element: " << endl;
  showNode(list);

  makeEmpty(list);
  cout << "After delete all element: " << endl;
  showNode(list);

  cout << "\n\n\n\n" << endl;

  LinkedList<string> *strList = new LinkedList<string>(0, NULL);
  addNode(strList, 0, (string) "hi");
  addNode(strList, 1, (string) "words");
  addNode(strList, 2, (string) "hello");
  addNode(strList, 3, (string) "monkey");
  addNode(strList, 4, (string) "computer");
  addNode(strList, 5, (string) "ubuntu");
  showNode(strList);
  removeNode(strList, 3);
  showNode(strList);
  pos = findPos(strList, (string) "hello");
  cout << "hello at position: " << pos << endl;
  makeEmpty(strList);
  showNode(strList);

  return 0;
}

template <class T> int addNode(LinkedList<T> *pList, int pos, T data) {
  // check errors

  // if LinkedList is empty
  if (pList->count == 0) {
    pList->headPtr = new node<T>(data, NULL);
    pList->count++;
    return 1;
  }

  // If placing at index 0
  if (pos == 0) {
    node<T> *newNode = new node<T>(data, pList->headPtr);
    pList->headPtr = newNode;
    pList->count++;
    return 1;
  }

  // generic case
  node<T> *newNode = new node<T>(data, NULL);
  node<T> *temp = pList->headPtr;
  for (int i = 1; i < pos; i++) {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  pList->count++;
  return 1;
}

template <class T> int removeNode(LinkedList<T> *pList, int pos) {
  // if empty
  if (pList->count == 0) {
    return -1;
  }

  // generic case
  node<T> *temp1 = pList->headPtr;
  node<T> *temp2;
  for (int i = 1; i < pos; i++) {
    temp1 = temp1->next;
  }
  temp2 = temp1->next;

  temp1->next = temp2->next;
  delete temp2;

  pList->count--;
  return 1;
}

template <class T> void showNode(LinkedList<T> *pList) {
  // if empty
  if (pList->count == 0) {
    // return;
  }

  // generic case
  node<T> *temp = pList->headPtr;
  while (temp != NULL) {
    cout << temp->nodeValue << endl;
    temp = temp->next;
  }
}

template <class T> bool isEmpty(LinkedList<T> *pList) {
  if (pList->count == 0) {
    return true;
  } else {
    return false;
  }
}

template <class T> int findPos(LinkedList<T> *pList, T data) {
  // if empty
  if (pList->count == 0) {
    return -1;
  }

  // generic case
  node<T> *temp = pList->headPtr;
  for (int i = 0; i < pList->count; i++) {
    if (temp->nodeValue == data) {
      return i;
    }
    temp = temp->next;
  }

  // if not found
  return -1;
}

template <class T> void makeEmpty(LinkedList<T> *pList) {
  // if empty
  if (pList->count == 0) {
    return;
  }

  // generic case
  node<T> *temp = pList->headPtr;

  while (temp != NULL) {
    pList->headPtr = pList->headPtr->next;
    delete temp;
    pList->count--;
    temp = pList->headPtr;
  }
}
