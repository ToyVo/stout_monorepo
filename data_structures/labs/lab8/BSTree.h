#ifndef BSTREE_CLASS
#define BSTREE_CLASS

#include <iostream>

using namespace std;

template <class T> struct BSTnode {
  BSTnode<T> *left;
  BSTnode<T> *right;
  T value;

  BSTnode(const T &initData = T(), BSTnode<T> *lt = NULL,
          BSTnode<T> *rt = NULL) {
    value = initData;
    left = lt;
    right = rt;
  }
};

template <class T> class BSTree {
public:
  // Constructor to build
  BSTree();
  // Destructor to return memory to the heap
  ~BSTree();
  void destroy(BSTnode<T> *curNode);

  bool search(const T &item) const;
  void insert(const T &item);

  void preOrder(BSTnode<T> *curNode);
  void inOrder(BSTnode<T> *curNode);
  void postOrder(BSTnode<T> *curNode);

  void remove(const T &item);
  void removeFromTree(BSTnode<T> *&p);

  void display(BSTnode<T> *curNode, int level);

  int calcSum(BSTnode<T> *curNode);
  int countNodes(BSTnode<T> *curNode);

  BSTnode<T> *root;
  int count;
};

// Implement member functions here

template <class T> BSTree<T>::BSTree() {
  root = NULL;
  count = 0;
}

// Destructor
template <class T> BSTree<T>::~BSTree() {
  destroy(root);
  cout << "Memory is freed by destructor" << endl;
}

template <class T> void BSTree<T>::destroy(BSTnode<T> *curNode) {
  if (curNode != NULL) {
    destroy(curNode->left);
    destroy(curNode->right);
    delete curNode;
    curNode = NULL;
  }
}

template <class T> bool BSTree<T>::search(const T &item) const {
  bool found = false;

  if (root == NULL)
    return false;

  BSTnode<T> *curNode = root;
  while (!found && curNode != NULL) {
    if (item < curNode->value) {
      curNode = curNode->left;
    } else if (item > curNode->value) {
      curNode = curNode->right;
    } else if (item == curNode->value)
      found = true;
  }
  return found;
}

template <class T> void BSTree<T>::insert(const T &item) {
  BSTnode<T> *current;
  BSTnode<T> *trail;
  BSTnode<T> *newNode = new BSTnode<T>(item);

  if (root == NULL) {
    root = newNode;
    count++;
    return;
  }

  current = root;
  while (current != NULL) {
    trail = current;
    if (current->value > item)
      current = current->left;
    else
      current = current->right;
  }

  if (trail->value > item)
    trail->left = newNode;
  else
    trail->right = newNode;
  count++;
}

template <class T> void BSTree<T>::preOrder(BSTnode<T> *curNode) {
  if (curNode != NULL) {
    cout << curNode->value << endl;
    preOrder(curNode->left);
    preOrder(curNode->right);
  }
}

template <class T> void BSTree<T>::inOrder(BSTnode<T> *curNode) {
  if (curNode != NULL) {
    preOrder(curNode->left);
    cout << curNode->value << endl;
    preOrder(curNode->right);
  }
}

template <class T> void BSTree<T>::postOrder(BSTnode<T> *curNode) {
  if (curNode != NULL) {
    preOrder(curNode->left);
    preOrder(curNode->right);
    cout << curNode->value << endl;
  }
}

template <class T> void BSTree<T>::remove(const T &item) {
  BSTnode<T> *current;
  BSTnode<T> *trail;
  bool found = false;

  if (root == NULL)
    return;

  current = root;
  trail = root;

  while ((current != NULL) && (!found)) {
    if (current->value == item) {
      found = true;
      cout << current->value << item << endl;
    } else {
      trail = current;
      if (current->value > item)
        current = current->left;
      else
        current = current->right;
    }
  }

  if (current == NULL) {
    cout << "not found" << endl;
    return;
  }

  if (found) {
    cout << current->value << endl;
    if (current == root)
      removeFromTree(root);
    else if (trail->value > item)
      removeFromTree(trail->left);
    else
      removeFromTree(trail->right);
    count--;
  }
}

template <class T> void BSTree<T>::removeFromTree(BSTnode<T> *&p) {
  BSTnode<T> *temp;
  if (p->left == NULL && p->right == NULL) {
    cout << "no children" << endl;
    temp = p;
    p = NULL;
    delete temp;
  } else if (p->left != NULL && p->right == NULL) {
    cout << "has left child" << endl;
    temp = p;
    p = temp->left;
    delete temp;
  } else if (p->right != NULL && p->left == NULL) {
    cout << "has right child" << endl;
    temp = p;
    p = temp->right;
    delete temp;
  } else {
    cout << "has two children" << endl;
    BSTnode<T> *current = p->left;
    BSTnode<T> *trail = NULL;
    while (current->right != NULL) {
      trail = current;
      current = current->right;
    }
    p->value = current->value;
    if (trail == NULL)
      p->left = current->left;
    else
      trail->right = current->left;
    delete current;
  }
}

template <class T> void BSTree<T>::display(BSTnode<T> *curNode, int level) {
  int i;
  if (curNode != NULL) {
    display(curNode->right, level + 1);
    cout << endl;

    if (curNode == root)
      cout << "Root->:  ";

    else {
      for (i = 0; i < level; i++)
        cout << "       ";
    }
    cout << curNode->value;
    display(curNode->left, level + 1);
  }
}

template <class T> int BSTree<T>::calcSum(BSTnode<T> *curNode) {
  if (curNode == NULL)
    return 0;
  return calcSum(curNode->left) + calcSum(curNode->right) + curNode->value;
}

template <class T> int BSTree<T>::countNodes(BSTnode<T> *curNode) {
  if (curNode == NULL)
    return 0;
  return 1 + countNodes(curNode->right) + countNodes(curNode->left);
}

#endif // BSTREE_CLASS (Must be last line of code)
