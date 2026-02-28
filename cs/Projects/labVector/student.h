#include <string>

using namespace std;

class Student {
private:
  string name;
  string phone;

public:
  Student();
  Student(string, string);
  void setAll(string, string);
  void setName(string);
  void setPhone(string);
  string getName();
  string getPhone();
  void print();
};