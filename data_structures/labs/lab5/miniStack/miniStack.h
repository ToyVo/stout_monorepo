#include "d_except.h" // for underflowError exception
#include <vector>     // vector class used by object composition

using namespace std;

template <class T> class miniStack {
public:
  miniStack();
  // constructor. create an empty stack

  void push(const T &item);
  // push (insert) item onto the stack.
  // Postcondition: the stack has a new topmost element and
  // the stack size increases by 1

  void pop();
  // remove the item from the top of the stack.
  // Precondition: the stack is not empty.
  // if the stack is empty, the function throws
  // the underflowError exception

  T &top();
  // return a reference to the element on the top
  // of the stack.
  // Precondition: the stack is not empty.
  // if the stack is empty, the function throws
  // the underflowError exception
  const T &top() const;
  // constant version of top()

  bool empty() const;
  // determine whether the stack is empty

  int size() const;
  // return the number of elements in the stack

private:
  vector<T> stackVector;
  // a vector object maintains the stack items and size
};

// Empty method as the vector is already created in the header
template <class T> miniStack<T>::miniStack() {}

// push item on the stack by inserting it at
// the rear of the vector
template <class T> void miniStack<T>::push(const T &item) {
  stackVector.push_back(item);
}

// if (empty())	throw underflowError("miniStack pop(): stack empty");
// pop the stack by removing the item at the rear of the vector
template <class T> void miniStack<T>::pop() {
  if (empty())
    throw underflowError("miniStack pop(): stack empty");
  stackVector.pop_back();
  return;
}

// if (empty())	throw underflowError("miniStack pop(): stack empty");
// the top of the stack is at the rear of the vector
// return the element at the rear of the vector
template <class T> T &miniStack<T>::top() {
  if (empty())
    throw underflowError("miniStack pop(): stack empty");

  return stackVector.back();
}

// constant version of top() with same internal method code
template <class T> const T &miniStack<T>::top() const {
  if (empty())
    throw underflowError("miniStack pop(): stack empty");

  return stackVector.back();
}

// if miniStack size is 0 then true, otherwise false
template <class T> bool miniStack<T>::empty() const {
  if (stackVector.size() == 0)
    return true;
  return false;
}

// return number of elements in the miniStack
template <class T> int miniStack<T>::size() const { return stackVector.size(); }
