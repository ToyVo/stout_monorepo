#include <iomanip>
#include <iostream>

using namespace std;

#include "time24.h"

// ***********************************************************
//      time24 class implementation
// ***********************************************************

// set minute and hour within their proper ranges
void time24::normalizeTime() {
  int extraHours = minute / 60;

  // set minute in range 0 to 59
  minute %= 60;

  // update hour. set in range 0 to 23
  hour = (hour + extraHours) % 24;
}

// Problem 2 here constructor. initialize time data
time24::time24() {
  hour = 0;
  minute = 0;
}

time24::time24(int m) {
  hour = 0;
  minute = m;
  normalizeTime();
}

time24::time24(int h, int m) {
  hour = h;
  minute = m;
  // put hour and minute in correct range
  normalizeTime();
}

// add m minutes to the time
void time24::addTime(int m) {
  // add m to minute. minute may exceed 59, so normalize
  minute += m;
  normalizeTime();
}
// Problem 4 insert method here (be sure to add to header file)

void time24::subtractHour(int h) {
  minute += (hour * 60);
  minute -= (h * 60);
  hour = 0;
  normalizeTime();
}

time24 time24::duration(const time24 &t) {
  // convert current time and time t to minutes
  int currTime = hour * 60 + minute;
  int tTime = t.hour * 60 + t.minute;

  // if t is earlier than the current time, throw an exception
  if (tTime < currTime)
    throw rangeError("time24 duration(): argument is an earlier time");
  else
    // create an anonymous object as the return value
    return time24(0, tTime - currTime);
}

void time24::readTime() {
  char colonSeparator;

  cin >> hour >> colonSeparator >> minute;
  // make sure hour and minute are in range
  normalizeTime();
}

// output time in the format <hour>:<minute>
void time24::writeTime() const {
  // the implementation uses stream handling functions
  // not discussed in the book. consult your compiler
  // help system for details

  // save current format flags and fill character
  ios_base::fmtflags currentFlags = cout.flags();
  char currentFill = cout.fill();

  // set fill char to ' ' and enable right justification
  cout.fill(' ');
  cout.setf(ios::right, ios::adjustfield);

  // output the hour
  cout << setw(2) << hour << ':';

  // set fill char to '0' and output the minute
  cout.fill('0');
  cout << setw(2) << minute << "  ";

  // restore the fill char and the format flags
  cout.fill(currentFill);
  cout.setf(currentFlags);
}

int time24::getHour() const { return hour; }

int time24::getMinute() const { return minute; }

// compare hours and minutes
bool operator==(const time24 &lhs, const time24 &rhs) {
  return lhs.hour == rhs.hour && lhs.minute == rhs.minute;
}

// convert the hour and minute values for each operand to
// minutes. compare lhs in minutes with rhs in minutes
bool operator<(const time24 &lhs, const time24 &rhs) {
  return (lhs.hour * 60 + lhs.minute) < (rhs.hour * 60 + rhs.minute);
}

bool operator>(const time24 &lhs, const time24 &rhs) {
  return (lhs.hour * 60 + lhs.minute) > (rhs.hour * 60 + rhs.minute);
}

// create an anonymous object with hour = lhs.hour + rhs.hour
// and minute = lhs.minute+rhs.minute.
time24 operator+(const time24 &lhs, const time24 &rhs) {
  return time24(lhs.hour + rhs.hour, lhs.minute + rhs.minute);
}

// create an anonymous object with hour = lhs.hour and
// minute = lhs.minute + min.
time24 operator+(const time24 &lhs, int min) {
  return time24(lhs.hour, lhs.minute + min);
}

// return the value rhs + min that is computed by
//    time24 operator+ (const time24& lhs, int min)
time24 operator+(int min, const time24 &rhs) { return rhs + min; }

// using the < operator, check whether lhs < rhs is true. if so
// terminate; otherwise return a time24 result built
// using the constructor
time24 operator-(const time24 &lhs, const time24 &rhs) {
  if (lhs < rhs)
    throw rangeError(
        "time24 operator-: Cannot subtract later from earlier time");

  // convert each object to minutes and compute the
  // difference in minutes. return the time24 object
  // having 0 as hours and the value of the difference
  // as minutes
  return time24(0, (lhs.hour * 60 + lhs.minute) - (rhs.hour * 60 + rhs.minute));
}

// implement += by using addition with operands *this and rhs
time24 &time24::operator+=(const time24 &rhs) {
  // add *this and rhs using overloaded + operator
  *this = *this + rhs;

  // return a reference to the current object
  return *this;
}

// implement += by using addition with operands *this and min
time24 &time24::operator+=(int min) {
  // add *this and min using overloaded + operator
  *this = *this + min;

  // return a reference to the current object
  return *this;
}

// overload stream operator >>. input has the form
//   hour:minute
istream &operator>>(istream &istr, time24 &t) {
  char separatorChar;

  istr >> t.hour >> separatorChar >> t.minute;
  // make sure hour and minute are in range
  t.normalizeTime();

  // return the stream
  return istr;
}

// overload stream operator <<. output in the form
//   hour:minute
ostream &operator<<(ostream &ostr, const time24 &t) {
  // the implementation uses stream handling functions
  // not discussed in the book. consult your compiler
  // help system for details

  // save current format flags and fill character
  ios_base::fmtflags currentFlags = ostr.flags();
  char currentFill = ostr.fill();

  // set fill char to ' ' and enable right justification
  ostr.fill(' ');
  ostr.setf(ios::right, ios::adjustfield);

  // output the hour
  ostr << setw(2) << t.hour << ':';

  // set fill char to '0' and output the minute
  ostr.fill('0');
  ostr << setw(2) << t.minute;

  // restore the fill char and the format flags
  ostr.fill(currentFill);
  ostr.setf(currentFlags);

  return ostr;
}
