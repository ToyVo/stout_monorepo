#include "student.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<Student> list;
  Student temp;

  list.push_back(Student("Smith, John", "232-1234"));
  list.push_back(Student("Doe, Jane", "232-2345"));
  list.push_back(Student("Hall, Monty", "232-1234"));
  list.push_back(Student("Ketchum, Hank", "232-1234"));
  list.push_back(Student("Jones, Ed", "232-1234"));

  list[4].setAll("Diekvoss, Collin", "634-7889");
  list[0].setName("me");
  list.erase(list.begin() + 3);
  list.insert(list.begin() + 4, Student("Charlie Brown", "123-4567"));

  for (int a = 0; a < list.size(); a++) {
    list[a].print();
  }

  system("pause");
  return 0;
}
