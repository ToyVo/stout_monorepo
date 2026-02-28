// This program demonstrates that string literals
// are pointers to char
#include "MyString.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

void testStringLiteral();
void testStringCmp1();
void testStringCmp2();
void testStringCmp3();
void demo1();
void demo2();

int main() {
  testStringLiteral();

  testStringCmp1();
  testStringCmp2();
  testStringCmp3();
  demo1();
  demo2();

  system("pause");
  return 0;
}

void testStringLiteral() {
  const int LENGTH = 80; // Maximum length for string
  char line[LENGTH];     // Array of char

  // Read a string into the character array
  cout << "Enter a sentence of no more than " << LENGTH - 1 << " characters:\n";
  cin.getline(line, LENGTH);
  cout << "The sentence you entered is:\n";

  // Loop through the array printing each character
  for (int index = 0; line[index] != '\0'; index++) {
    cout << line[index];
  }

  cout << endl;

  // Print the characters stored in line (except '\0')
  cout << "Printing characters in line " << endl;
  cout << line << endl;
}

void testStringCmp1() {
  cout << "string literal comparisons using standard opearator ==" << endl;
  // Two arrays for holding two strings
  const int LENGTH = 40;
  char firstString[LENGTH], secondString[LENGTH];

  // Read two strings
  cout << "Enter a string: ";
  cin.getline(firstString, LENGTH);
  cout << "Enter another string: ";
  cin.getline(secondString, LENGTH);

  // Attempt to compare the two strings using ==
  if (firstString == secondString)
    cout << "You entered the same string twice.\n";
  else
    cout << "The strings are not the same.\n";
}

void testStringCmp2() {
  cout << "string literal comparison using cstring function strcmp() " << endl;
  // Two arrays for two strings
  const int LENGTH = 40;
  char firstString[LENGTH], secondString[LENGTH];

  // Read two strings
  cout << "Enter a string: ";
  cin.getline(firstString, LENGTH);
  cout << "Enter another string: ";
  cin.getline(secondString, LENGTH);

  // Compare the strings for equality with strcmp
  if (strcmp(firstString, secondString) == 0)
    cout << "You entered the same string twice.\n";
  else
    cout << "The strings are not the same.\n";
}

void testStringCmp3() {
  cout << "string literal comparison using a user-defined class MyString"
       << endl;
  // Two arrays for holding two strings
  const int LENGTH = 40;
  char firstString[LENGTH], secondString[LENGTH];

  // Read two strings
  cout << "Enter a string: ";
  cin.getline(firstString, LENGTH);
  cout << "Enter another string: ";
  cin.getline(secondString, LENGTH);

  MyString s1(firstString);
  MyString s2(secondString);

  // Attempt to compare the two strings using ==
  if (s1 == s2)
    cout << "You entered the same string twice.\n";
  else
    cout << "The strings are not the same.\n";
}

void demo1() {
  MyString object1("This"), object2("is");
  MyString object3("a test.");
  MyString object4 = object1; // Call copy constructor
  MyString object5("is only a test.");
  char string1[] = "a test.";

  cout << "object1: " << object1 << endl;
  cout << "object2: " << object2 << endl;
  cout << "object3: " << object3 << endl;
  cout << "object4: " << object4 << endl;
  cout << "object5: " << object5 << endl;
  cout << "string1: " << string1 << endl;
  object1 += " ";
  object1 += object2;
  object1 += " ";
  object1 += object3;
  object1 += " ";
  object1 += object4;
  object1 += " ";
  object1 += object5;
  cout << "object1: " << object1 << endl;
}

void demo2() {
  MyString name1("Billy"), name2("Sue");
  MyString name3("Joe");
  MyString string1("ABC"), string2("DEF");

  cout << "name1: " << name1.data() << endl;
  cout << "name2: " << name2.data() << endl;
  cout << "name3: " << name3.data() << endl;
  cout << "string1: " << string1.data() << endl;
  cout << "string2: " << string2.data() << endl;
  if (name1 == name2)
    cout << "name1 is equal to name2.\n";
  else
    cout << "name1 is not equal to name2.\n";
  if (name3 == "Joe")
    cout << "name3 is equal to Joe.\n";
  else
    cout << "name3 is not equal to Joe.\n";
  if (string1 > string2)
    cout << "string1 is greater than string2.\n";
  else
    cout << "string1 is not greater than string2.\n";
  if (string1 < string2)
    cout << "string1 is less than string2.\n";
  else
    cout << "string1 is not less than string2.\n";
  if (string1 >= string2)
    cout << "string1 is greater than or equal to "
         << "string2.\n";
  else
    cout << "string1 is not greater than or equal to "
         << "string2.\n";
  if (string1 >= "ABC")
    cout << "string1 is greater than or equal to "
         << "ABC.\n";
  else
    cout << "string1 is not greater than or equal to "
         << "ABC.\n";
  if (string1 <= string2)
    cout << "string1 is less than or equal to "
         << "string2.\n";
  else
    cout << "string1 is not less than or equal to "
         << "string2.\n";
  if (string2 <= "DEF")
    cout << "string2 is less than or equal to "
         << "DEF.\n";
  else
    cout << "string2 is not less than or equal to "
         << "DEF.\n";
}