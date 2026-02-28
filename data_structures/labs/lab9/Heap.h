#include <cmath>
#include <vector>

using namespace std;

template <typename T> class Heap {
public:
  // Constructor: creates an empty heap.
  Heap() {}
  // add an item to the heap and re-adjust tree accordingly
  void enqueue(const T &entry);
  // remove an item from the heap and re-adjust tree accordingly
  T dequeue();
  // return the current size of the bag (size of v)
  int size() const { return v.size(); }
  // print all values stored in the heap
  void printHeap();

private:
  // restore heap by swapping the element up the heap
  void reheapifyUp(int curSpot);
  // restore heap by swapping the element down the heap
  void reheapifyDown(int curSpot);
  // Heap elements stored in a vector v
  vector<T> v;
};

template <typename T> void Heap<T>::enqueue(const T &entry) {
  // Push key onto back of v vector
  v.push_back(entry);
  // call reheapifyUp with the index of the newly inserted key
  reheapifyUp(v.size() - 1);
}

template <typename T> void Heap<T>::reheapifyUp(int curSpot) {
  // Stop at root or when element less than parent
  while (curSpot != 0 && v[curSpot] > v[((curSpot - 1) / 2)]) {
    // Swap element at curSpot up the tree to form a heap.
    swap(v[curSpot], v[((curSpot - 1) / 2)]);
    // Find the index of your parent node
    curSpot = ((curSpot - 1) / 2);
  }
}

template <typename T> T Heap<T>::dequeue() {
  // Store root element on top of the heap in a temp variable
  T tempRoot = v[0];
  // copy last element into first location
  v[0] = v.back();
  // remove last element (back of vector)
  v.pop_back();
  // reheapify the new root element down the tree with reheapifyDown
  reheapifyDown(0);
  // return  stored temp element
  return tempRoot;
}

template <typename T> void Heap<T>::reheapifyDown(int curSpot) {
  // Declare child indices and largest index
  int lchild = curSpot * 2 + 1;
  int rchild = curSpot * 2 + 2;
  // While not at a leaf node
  while (lchild < size()) {
    // Find largest of two children (check if rchild exists)
    int largest = lchild;
    if (rchild <= (v.size() - 1)) {
      if (v[rchild] > v[lchild]) {
        largest = rchild;
      }
    }
    // break from the loop is both children less than parent
    if (v[curSpot] > v[largest]) {
      break;
    }
    // swap curSpot and parent elements
    swap(v[curSpot], v[largest]);
    // Reset curSpot and its children indices
    curSpot = largest;
    lchild = curSpot * 2 + 1;
    rchild = curSpot * 2 + 2;
  }
}

template <typename T> void Heap<T>::printHeap() {
  int count = 1;
  int newLineIndex = 0;

  for (int i = 0; i < size(); i++) {
    cout << v[i] << "\t";

    if (pow(2, newLineIndex) == count) {
      cout << endl;
      newLineIndex++;
      count = 0;
    }
    count++;
  }
  cout << endl << endl;
}
