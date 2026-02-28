#include <iostream>
#include <string>
using namespace std;
class phone {
private:
  string number;

public:
  class hasChar {};
  class tooLong {};
  phone() {}
  string isNumber() {
    cin >> number;
    if (number.length() > 10)
      throw tooLong();
    for (int a = 0; a < number.length(); a++) {
      if (!isdigit(number[a])) {
        throw hasChar();
      }
    }
    return number;
  }
};