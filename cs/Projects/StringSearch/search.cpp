#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void main() {
  ifstream in;
  string phrase;
  string input;
  int count = 0;

  cout << "enter in a file name you would like to search, includeing file "
          "extention, make sure it is in the correct directory."
       << endl;
  cin >> phrase;
  in.open(phrase, ios::in);
  if (!in) {
    cout << "The file was not found." << endl;
    return;
  }
  cout << "enter in the phrase that you would like to search for" << endl;
  cin >> phrase;

  while (in >> input) {
    if (input == phrase)
      count++;
  }
  cout << "Shows up " << count << " times" << endl;

  system("pause");
  return;
}