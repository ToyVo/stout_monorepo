#include <cctype>
#include <iostream>
#include <string>

using namespace std;

void main() {
  string s1, s2;
  int count = 0;
  size_t found;

  cout << "enter in a string to search within" << endl;
  getline(cin, s1);
  cout << "enter in a string to search for" << endl;
  getline(cin, s2);

  found = s1.find(s2);

  while (found != string::npos) {
    cout << s2 << " found at: " << found << endl;
    count++;
    found = s1.find(s2, found + s2.length());
  }
  cout << s2 << " shows up " << count << " times" << endl;

  for (int a = 0; a < s1.length(); a++) {
    s1[a] = tolower(s1[a]);
  }

  system("pause");
  return;
}