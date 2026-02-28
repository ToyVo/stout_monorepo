#include <cstdlib>
#include <iostream>

#include "BSTree.h"

using namespace std;

int main() {
  BSTree<int> tree;

  int choice, item;
  bool flag = true;
  while (flag) {
    cout << "\n-----------------" << endl;
    cout << "Operations on BST" << endl;
    cout << "-----------------" << endl;
    cout << "1.Insert a value (integer) " << endl;
    cout << "2.Remove a value (integer) " << endl;
    cout << "3.Inorder traversal" << endl;
    cout << "4.Preorder traversal" << endl;
    cout << "5.Postorder traversal" << endl;
    cout << "6.Display" << endl;
    cout << "7.Quit" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter the number to be inserted : ";
      cin >> item;
      tree.insert(item);
      break;
    case 2:
      cout << "Enter the number to be deleted : ";
      cin >> item;
      tree.remove(item);
      break;
    case 3:
      cout << "Inorder Traversal of BST:  ";
      tree.inOrder(tree.root);
      cout << endl;
      break;
    case 4:
      cout << "Preorder Traversal of BST:  ";
      tree.preOrder(tree.root);
      cout << endl;
      break;
    case 5:
      cout << "Postorder Traversal of BST:  ";
      tree.postOrder(tree.root);
      cout << endl;
      break;
    case 6:
      cout << "Display BST:" << endl;
      tree.display(tree.root, 1);
      cout << endl;
      break;
    case 7:
      flag = false;
      break;
    default:
      cout << "Wrong choice" << endl;
    }
  }
  return 0;
}
