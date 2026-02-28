#include "counter.h"

counter::counter() { count = 0; }

counter::~counter() {}

int counter::getCount() { return count; }

void counter::increaseBy(int x) { count += x; }

bool operator==(counter lhs, counter rhs) {
  if (lhs.count == rhs.count)
    return true;
  else
    return false;
}