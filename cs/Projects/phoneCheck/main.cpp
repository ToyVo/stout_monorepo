#include "phone.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  phone number;
  string num;
  cout << "enter in a phone number this program will check to make sure there "
          "are no chars"
       << endl;
  try {
    num = number.isNumber();
    cout << num << endl;
  } catch (phone::tooLong) {
    cout << "this phone number is longer than 10" << endl;
  } catch (phone::hasChar) {
    cout << "this has some characters" << endl;
  }
  system("pause");
  return 1;
}