#include <string>

using namespace std;

class Date {
private:
  int day;
  string month;
  int year;

public:
  Date();
  Date(int, string, int);
  void setDay(int);
  void setMonth(string);
  void setYear(int);
  int getDay();
  string getMonth();
  int getYear();
  void print();
};