#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define KEY_SIZE 10
#define TABLE_SIZE 5

using namespace std;

// structures we need to implement a hash table
// struct Element

typedef struct Element {
  char key[KEY_SIZE];
} Element;

// class NodeLink

class ListNode {
public:
  Element item;
  ListNode *link;
  ListNode(const Element &value, ListNode *ptr) {
    item = value;
    link = ptr;
  }
};

// create a hash table

ListNode *hashTable[TABLE_SIZE];

// local functions to manipuate a hasth table
void initTable(ListNode *ht[]);
int transform(char *key);
int hashFunction(char *key);
void addHashTable(Element item, ListNode *ht[]);
void removeHashTable(Element item, ListNode *ht[]);
ListNode *hashSearch(Element item, ListNode *ht[]);
void printHashTable(ListNode *ht[]);

// main function
int main() {
  initTable(hashTable);

  Element entry;

  int op;

  while (1) {
    cout << "Select an option" << endl;
    cout << "(1: Add, 2 : Search, 3: Remove, 4 : Print, 5 : Terminate) = "
         << endl;
    cin >> op;
    if (op == 5)
      break;

    else if (op == 1) {
      printf("Enter a key for addition: ");
      cin >> entry.key;
      addHashTable(entry, hashTable);
    } else if (op == 2) {
      printf("Enter a key for searching: ");
      cin >> entry.key;
      hashSearch(entry, hashTable);
    } else if (op == 3) {
      printf("Enter a key for removing: ");
      cin >> entry.key;
      removeHashTable(entry, hashTable);
    } else if (op == 4)
      printHashTable(hashTable);

    else
      cout << "Wrong option!" << endl;
  }
  return 0;
}

// implement all functions declared above

void initTable(ListNode *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    ht[i] = NULL;
  }
}

int transform(char *key) {
  int total = 0;
  for (int i = 0; key[i] != '\0'; i++) {
    total += (int)key[i];
  }
  return total;
}

int hashFunction(char *key) { return transform(key) % TABLE_SIZE; }

void addHashTable(Element item, ListNode *ht[]) {
  int hashValue = hashFunction(item.key);
  ListNode *node = ht[hashValue];
  while (node != NULL) {
    if (strcmp(item.key, node->item.key) == 0) {
      cout << "duplicate key" << endl;
      return;
    }
    node = node->link;
  }
  node = new ListNode(item, ht[hashValue]);
  ht[hashValue] = node;
}

void removeHashTable(Element item, ListNode *ht[]) {
  int hashValue = hashFunction(item.key);
  ListNode *node = ht[hashValue];
  ListNode *temp = ht[hashValue];
  while (node != NULL) {
    if (strcmp(item.key, node->item.key) == 0) {
      // if the item that is being deleted is first
      if (temp->item.key == node->item.key) {
        ht[hashValue] = node->link;
        delete node;
        return;
      }
      // if item to be deleted has been found
      temp->link = node->link;
      delete node;
      return;
    }
    // temp should always be one behind node, unless item being deleted is first
    temp = node;
    node = node->link;
  }
}

ListNode *hashSearch(Element item, ListNode *ht[]) {
  int hashValue = hashFunction(item.key);
  ListNode *node = ht[hashValue];
  while (node != NULL) {
    if (strcmp(item.key, node->item.key) == 0) {
      cout << "found key" << endl;
      return node;
    }
    node = node->link;
  }
  cout << "failed to find key" << endl;
  return NULL;
}

void printHashTable(ListNode *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    cout << i << ":";
    ListNode *node = ht[i];
    while (node != NULL) {
      cout << node->item.key << "\t";
      node = node->link;
    }
    cout << endl;
  }
}