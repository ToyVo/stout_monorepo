#include "miniStack.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int points = 0;

  miniStack<char> h;
  points += 5;
  cout << "Constructor worked. Points: " << points << endl;
  h.push('s');
  points += 5;
  cout << "Push worked. Points: " << points << endl;
  if (h.size() == 1 && !h.empty()) {
    points += 5;
    cout << "Size works. Points now " << points << endl;
  }

  if (!h.empty()) {
    points += 5;
    cout << "Empty works. Points now " << points << endl;
  }
  if (h.top() == 's') {
    points += 5;
    cout << "You are correct top works Points are " << points << endl;
  }
  h.pop();
  if (h.size() == 0) {
    points += 5;
    cout << "Wow you tested both pop and size in one shot Points now " << points
         << endl;
  }
  if (h.empty() && h.size() == 0) {
    cout << "No minus points!, Wow you tested both size and empty in one shot "
            "Points still "
         << points << endl;
  } else {
    points -= 3;
    cout
        << "Oops tested both size and empty in one shot  and failed Points now "
        << points << endl;
  }

  return EXIT_SUCCESS;
}
