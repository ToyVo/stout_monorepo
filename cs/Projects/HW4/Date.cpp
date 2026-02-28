#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date() {
  setDay(1);
  setMonth("January");
  setYear(2001);
}

Date::Date(int d, string m, int y) {
  setDay(d);
  setMonth(m);
  setYear(y);
}

void Date::setDay(int d) {
  if (d >= 1 && d <= 31)
    day = d;
  else {
    cout << "Enter in a new vale making sure it is between 1 and 31: ";
    cin >> d;
    setDay(d);
  }
}

void Date::setMonth(string m) {
  if (m == "January" || m == "February" || m == "March" || m == "April" ||
      m == "May" || m == "June" || m == "July" || m == "August" ||
      m == "September" || m == "October" || m == "November" || m == "December")
    month = m;
  else {
    cout << "Months are only recognized in the format of spelled out "
            "completely with a capitol first letter"
         << endl;
    cout << "January, February, March, April, May, June, July, August, "
            "September, October, November, December"
         << endl;
    cout << "Enter in a recognized month: ";
    cin >> m;
    setMonth(m);
  }
}

void Date::setYear(int y) { year = y; }

int Date::getDay() { return day; }

string Date::getMonth() { return month; }

int Date::getYear() { return year; }

void Date::print() { cout << day << " " << month << " " << year << endl; }