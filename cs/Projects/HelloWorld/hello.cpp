#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string name;
  int age;

  cout << "Hello World!\n";

  cout << "What is your name?\n";
  cin >> name;

  cout << "What is your age?\n";
  cin >> age;

  cout << name << " you are " << age << " years old." << endl;

  getch();
  return 0;
}