#ifndef NULL
#include <cstddef>
#endif // NULL

template <typename T> class node {
public:
  // data members
  T nodeValue;
  node<T> *next;
  node<T> *previous;
  // constructors

  node(const T &item) {
    nodeValue = item;
    next = NULL;
    previous = NULL;
  }
};
