#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define KEY_SIZE 10
#define TABLE_SIZE 13

using namespace std;

// structures we need to implement a hash table
// struct Element

typedef struct Element {
  char key[KEY_SIZE];
  bool written;
} Element;

// create a hash table

Element hashTable[TABLE_SIZE];

// local functions to manipuate a hasth table
void initTable(Element ht[]);
int transform(char *key);
int hashFunction(char *key);
void addHashTable(Element item, Element ht[]);
void hashSearch(Element item, Element ht[]);
void printHashTable(Element ht[]);
void deleteKey(Element item, Element ht[]);

int main() {
  initTable(hashTable);

  Element entry;

  int op;
  while (1) {
    cout << "Select an option (1: Add, 2: Search, 3: Print, 4: Delete, 5: "
            "Terminate) = "
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
    } else if (op == 3)
      printHashTable(hashTable);

    else if (op == 4) {
      printf("Enter a key for deleting: ");
      cin >> entry.key;
      deleteKey(entry, hashTable);
    }

    else
      cout << "Wrong option! \n Options (1: Add, 2: Search, 3: Print, 4: "
              "Delete, 5: Terminate) = "
           << endl;
  }

  return 0;
}

// implement all functions declared above

void initTable(Element ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    ht[i].key[0] = '\0';
    ht[i].written = false;
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

void addHashTable(Element item, Element ht[]) {
  int hashValue = hashFunction(item.key);
  int i = hashValue;

  while (strlen(ht[i].key) != 0) {
    if (strcmp(item.key, ht[i].key) == 0 && ht[i].written == true) {
      cout << "duplicate key" << endl;
      return;
    }
    i = (i + 1) % TABLE_SIZE;
    if (i == hashValue && ht[i].written == true) {
      cout << "Table Full" << endl;
      return;
    }
  }
  ht[i] = item;
  ht[i].written = true;
}

void hashSearch(Element item, Element ht[]) {
  int hashValue = hashFunction(item.key);
  int i = hashValue;

  while (strlen(ht[i].key) != 0) {
    if (strcmp(item.key, ht[i].key) == 0 && ht[i].written == true) {
      cout << "found key" << endl;
      return;
    }
    i = (i + 1) % TABLE_SIZE;
    if (i == hashValue) {
      cout << "Key not found" << endl;
      return;
    }
  }
}

void printHashTable(Element ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (ht[i].written == true)
      cout << i << ": " << ht[i].key << endl;
    if (ht[i].written == false)
      cout << i << ":" << endl;
  }
  cout << endl;
}

void deleteKey(Element item, Element ht[]) {
  int hashValue = hashFunction(item.key);
  int i = hashValue;

  while (strlen(ht[i].key) != 0) {
    if (strcmp(item.key, ht[i].key) == 0 && ht[i].written == true) {
      ht[i].written = false;
      ht[i].key[0] = '\0';
      return;
    }
    i = (i + 1) % TABLE_SIZE;
    if (i == hashValue) {
      cout << "Key not found" << endl;
      return;
    }
  }
}