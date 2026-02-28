#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstdlib> // For exit() function
#include <cstring> // For string library functions
#include <iostream>

using namespace std;
const int SIZE = 256;

class MyString {
private:
  char *str;
  int len;

public:
  // Constructors
  MyString() {
    str = new char[1];
    str[0] = '\0';
    len = 0;
  }
  MyString(const char *s);
  MyString(const MyString &);

  // Destructor
  ~MyString() { delete[] str; }

  // Various member functions and operators
  int length() const { return len; }
  char *data() { return str; };
  MyString operator+=(MyString);
  MyString operator=(MyString);

  // Various overloaded operators
  friend bool operator==(MyString, MyString);
  friend bool operator!=(MyString, MyString);
  friend bool operator>(MyString, MyString);
  friend bool operator<(MyString, MyString);
  friend bool operator>=(MyString, MyString);
  friend bool operator<=(MyString, MyString);
  friend ostream &operator<<(ostream &, MyString);
  friend istream &operator>>(istream &, MyString &);
};
#endif