#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vec);

int main() {
  const int SIZE = 5;
  vector<int> vec1(SIZE);

  cout << "start with vector size: " << SIZE << endl;
  print(vec1);

  for (int i = 0; i < vec1.size(); i++) {
    vec1[i] = i + 1;
  }
  print(vec1);
  cout << "Size of vector: " << vec1.size() << endl;
  cout << "Capacity: " << vec1.capacity() << endl;

  // test 1
  cout << "\ntest 1" << endl;
  vec1.push_back(6);
  vec1.push_back(7);

  cout << "added two more integers" << endl;
  print(vec1);
  cout << "Size of vector: " << vec1.size() << endl;
  cout << "Capacity: " << vec1.capacity() << endl;

  // test 2
  cout << "\ntest 2" << endl;
  vec1.push_back(8);
  vec1.push_back(9);
  vec1.push_back(10);
  vec1.push_back(11);

  cout << "added four more integers " << endl;
  print(vec1);
  cout << "Size of vector: " << vec1.size() << endl;
  cout << "Capacity: " << vec1.capacity() << endl;

  // test 3
  cout << "\ntest 3" << endl;
  vec1.pop_back();
  vec1.pop_back();

  cout << "deleted two integers from the back" << endl;
  print(vec1);
  cout << "Size of vector: " << vec1.size() << endl;
  cout << "Capacity: " << vec1.capacity() << endl;

  // test 4
  cout << "\ntest 4" << endl;
  vec1.pop_back();
  vec1.pop_back();
  vec1.pop_back();
  vec1.pop_back();

  cout << "deleted four integers from the back" << endl;
  print(vec1);
  cout << "Size of vector: " << vec1.size() << endl;
  cout << "Capacity: " << vec1.capacity() << endl;

  // test 5
  cout << "\ntest 5" << endl;
  vec1.clear();
  cout << "cleared vector" << endl;
  print(vec1);
  cout << "Size of vector: " << vec1.size() << endl;
  cout << "Capacity: " << vec1.capacity() << endl;
  cout << "Is this vector empty? " << vec1.empty() << endl;

  // test 6
  cout << "\ntest 6" << endl;
  vec1.resize(25, 5);
  cout << "vector has been resized and initialized by 5" << endl;
  print(vec1);
  cout << "Size of vector: " << vec1.size() << endl;
  cout << "Capacity: " << vec1.capacity() << endl;

  // test 7
  cout << "\ntest 7" << endl;
  vec1.push_back(10);
  cout << "added one integer" << endl;
  cout << "Size of vector: " << vec1.size() << endl;
  cout << "Capacity: " << vec1.capacity() << endl;

  // test 8
  cout << "\ntest 8" << endl;
  vector<int> vec2;
  vec2.push_back(1);
  vec2.push_back(2);

  vec1.swap(vec2);

  cout << "vector has been swapped with another vector" << endl;
  print(vec1);
  cout << "Size of vector: " << vec1.size() << endl;
  cout << "Capacity: " << vec1.capacity() << endl;

  // test 9
  cout << "\ntest 9" << endl;
  vector<int>::iterator itr = vec1.begin();

  cout << "the first element: " << vec1[0] << " == " << *itr << endl;

  return EXIT_SUCCESS;
}

void print(vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
