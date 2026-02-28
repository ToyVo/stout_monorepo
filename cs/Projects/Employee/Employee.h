#include <string>

using namespace std;

class Employee {
private:
  string name;
  int idNumber;
  string department;
  string position;

public:
  Employee();
  Employee(string, int);
  Employee(string, int, string, string);
  void setName(string);
  void setID(int);
  void setDepartment(string);
  void setPosition(string);
  string getName();
  int getID();
  string getDepartment();
  string getPosition();
  void print();
};