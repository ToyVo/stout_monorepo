#ifndef NULL
#include <cstddef>
#endif // NULL

template <typename T> class node {
public:
  // data members
  T nodeValue;
  node<T> *next;

  // constructor
  node(const T &item = T(), node<T> *nextNode = NULL) {
    nodeValue = item;
    next = nextNode;
  }
};
