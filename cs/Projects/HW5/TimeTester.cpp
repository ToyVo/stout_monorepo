// File:TimeTester.cpp
// the program uses tests the time24 objects to compute the time

#include <iostream>
using namespace std;
#include "time24.h"

int main() {
  cout << "In the main method of TimeTester.cpp" << endl;
  time24 t1(7, 43);
  time24 t2(540);
  time24 t3(10, 20);
  time24 t4;
  t1.writeTime();
  t2.writeTime();
  t3.writeTime();
  t4.writeTime();
  t3.subtractHour(3);
  t3.writeTime();
  cout << t3.getHour() << ":" << t3.getMinute() << endl;
  try {
    time24 t5 = t1.duration(t2);
    t5.writeTime();
    time24 t6 = (t2 - t1);
    t6.writeTime();
    if (t5 == t6)
      cout << "duration is the same as minus" << endl;
    else
      cout << "duration is NOT the same as minus" << endl;
  } catch (const rangeError &re) // Handle exception defined in d_except.h
  {
    char ch;
    cerr << re.what() << endl;
    cin >> ch;
  }
  cout << endl;

  cout << "enter in a hour and minute value" << endl;
  cin >> t4;
  cout << t3 << " " << t4 << endl;

  if (t2 > t1)
    cout << t2 << ">" << t1 << endl;
  if (t3 < t4)
    cout << t3 << "<" << t4 << endl;

  system("pause");
  return 0;
}
