#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class node {
public:
  node(int item = 0, node *nextNode = NULL) {
    nodeValue = item;
    next = nextNode;
  }
  int getNodeValue() { return nodeValue; }
  void setNodeValue(int newValue) { nodeValue = newValue; }
  node *getNext() { return next; }
  void setNext(node *newNode) { next = newNode; }

private:
  int nodeValue;
  node *next;
};

class LinkedList {
public:
  LinkedList(int nodeCount, node *nextNode) {
    count = nodeCount;
    headPtr = nextNode;
  }
  node *getHeadPtr() { return headPtr; }
  void setHeadPtr(node *newNode) { headPtr = newNode; }
  int getCount() { return count; }
  void modifyCount(int i) { count += i; }

private:
  node *headPtr;
  int count;
};

int addNode(LinkedList *pList, int pos, int data);
int removeNode(LinkedList *pList, int pos);
void showNode(LinkedList *pList);
bool isEmpty(LinkedList *pList);
int findPos(LinkedList *pList, int data);
void makeEmpty(LinkedList *pList);

int main() {
  int pos;
  LinkedList *list = new LinkedList(0, NULL);

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

  return 0;
}

int addNode(LinkedList *pList, int pos, int data) {
  // check errors

  // if LinkedList is empty
  if (pList->getCount() == 0) {
    pList->setHeadPtr(new node(data, NULL));
    pList->modifyCount(1);
    return 1;
  }

  // If placing at index 0
  if (pos == 0) {
    node *newNode = new node(data, pList->getHeadPtr());
    pList->setHeadPtr(newNode);
    pList->modifyCount(1);
    return 1;
  }

  // generic case
  node *newNode = new node(data, NULL);
  node *temp = pList->getHeadPtr();
  for (int i = 1; i < pos; i++) {
    temp = temp->getNext();
  }
  newNode->setNext(temp->getNext());
  temp->setNext(newNode);
  pList->modifyCount(1);
  return 1;
}

int removeNode(LinkedList *pList, int pos) {
  // if empty
  if (pList->getCount() == 0) {
    return -1;
  }

  // generic case
  node *temp1 = pList->getHeadPtr();
  node *temp2;
  for (int i = 1; i < pos; i++) {
    temp1 = temp1->getNext();
  }
  temp2 = temp1->getNext();

  temp1->setNext(temp2->getNext());
  delete temp2;

  pList->modifyCount(-1);
  return 1;
}

void showNode(LinkedList *pList) {
  // if empty
  if (pList->getCount() == 0) {
    // return;
  }

  // generic case
  node *temp = pList->getHeadPtr();
  while (temp != NULL) {
    cout << temp->getNodeValue() << endl;
    temp = temp->getNext();
  }
}

bool isEmpty(LinkedList *pList) {
  if (pList->getCount() == 0) {
    return true;
  } else {
    return false;
  }
}

int findPos(LinkedList *pList, int data) {
  // if empty
  if (pList->getCount() == 0) {
    return -1;
  }

  // generic case
  node *temp = pList->getHeadPtr();
  for (int i = 0; i < pList->getCount(); i++) {
    if (temp->getNodeValue() == data) {
      return i;
    }
    temp = temp->getNext();
  }

  // if not found
  return -1;
}

void makeEmpty(LinkedList *pList) {
  // if empty
  if (pList->getCount() == 0) {
    return;
  }

  // generic case
  node *temp = pList->getHeadPtr();

  while (temp != NULL) {
    pList->setHeadPtr((pList->getHeadPtr()->getNext()));
    delete temp;
    pList->modifyCount(-1);
    temp = pList->getHeadPtr();
  }
}
