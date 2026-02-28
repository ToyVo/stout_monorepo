#include "counter.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void updateCounter(counter one);
void updateCounter2(counter &one);
void updateCounter3(counter *one);

int main() {
  counter one;
  cout << one.getCount() << endl;
  updateCounter(one);
  cout << one.getCount() << endl;

  updateCounter2(one);
  cout << one.getCount() << endl;

  updateCounter3(&one);
  cout << one.getCount() << endl;

  counter *two = new counter();
  cout << two->getCount() << endl;

  delete two;

  return EXIT_SUCCESS;
}

void updateCounter(counter one) { one.increaseBy(10); }

void updateCounter2(counter &one) { one.increaseBy(20); }

void updateCounter3(counter *one) { one->increaseBy(30); }