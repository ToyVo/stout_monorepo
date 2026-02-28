#include "Timer.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
  Timer t1;
  t1.setMinutes(10);
  cout << t1.getMinutes() << endl;
  t1.reset();
  cout << t1.getMinutes() << endl;
  system("pause");
  return 0;
}