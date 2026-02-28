#include <iostream>
#include <string>

using namespace std;

void main() {
  string password;
  bool lower = false, upper = false, digit = false;

  do {
    cout << "enter your password" << endl;
    cout << "It should have 6 charactors, one upper and lowercase letter and a "
            "number"
         << endl;
    cin >> password;

    if (password.length() < 6)
      cout << "password needs more than 6 character" << endl;
    for (int i = 0; i < password.length(); i++) {
      if (isupper(password[i]))
        upper = true;
      if (islower(password[i]))
        lower = true;
      if (isdigit(password[i]))
        digit = true;
    }

    if (!lower)
      cout << "Password needs a lower case letter" << endl;
    if (!upper)
      cout << "Password needs an upper case letter" << endl;
    if (!digit)
      cout << "Password needs a digit" << endl;
  } while (!(lower && upper && digit && password.length() >= 6));

  system("pause");
  return;
}