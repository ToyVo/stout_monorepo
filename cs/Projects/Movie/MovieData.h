#include <string>

using namespace std;

class MovieData {
private:
  string title;
  string director;
  int year;
  double time;
  double cost;
  double revenue;

public:
  MovieData();
  MovieData(string, string, int, double, double, double);
  void setTitle(string);
  void setDirector(string);
  void setYear(int);
  void setTime(double);
  void setCost(double);
  void setRevenue(double);
  string getTitle();
  string getDirector();
  int getYear();
  double getTime();
  double getCost();
  double getRevenue();
  void print();
};