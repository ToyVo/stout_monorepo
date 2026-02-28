#ifndef TIME24_H
#define TIME24_H

#include "d_except.h" // for rangeError exception

using namespace std;

class time24 {
public:
  // constructor initializes hour and minute
  time24();
  time24(int m);
  time24(int h, int m);

  void addTime(int m);
  // update time by adding m minutes to the current time
  // Precondition:  m must be >= 0
  // Postcondition: The new time is m minutes later

  void subtractHour(int h);
  // subratact time
  // precondition h >= 0
  // postcondition time is h hours earlier

  time24 duration(const time24 &t);
  // return the length of time from the current time to some later
  // time t as a time24 value
  // Precondition:  time t must not be earlier than the current time.
  // if it is, throw a rangeError exception

  void readTime();
  // input from the keyboard time in the form hh:mm
  // Postcondition: Assign value hh to hour and mm to minute and
  // adjust units to the proper range.

  void writeTime() const;
  // display on the screen the current time in the form hh:mm

  int getHour() const;
  // return the hour value for the current time

  int getMinute() const;
  // return the minute value for the current time

  // THESE FUNCTIONS ARE DISCUSSED IN CHAPTER 2 ON OPERATOR
  // OVERLOADING
  friend bool operator==(const time24 &lhs, const time24 &rhs);

  friend bool operator<(const time24 &lhs, const time24 &rhs);

  friend bool operator>(const time24 &lhs, const time24 &rhs);

  friend time24 operator+(const time24 &lhs, const time24 &rhs);
  // form and return lhs + rhs
  friend time24 operator+(const time24 &lhs, int min);
  // form and return lhs + min
  // Precondition:  min must be >= 0
  friend time24 operator+(int min, const time24 &rhs);
  // form and return min + rhs
  // Precondition:  min must be >= 0
  friend time24 operator-(const time24 &lhs, const time24 &rhs);
  // form and return lhs - rhs
  // Precondition: lhs >= rhs. if not, throw a rangeError exception
  time24 &operator+=(const time24 &rhs);
  // current object = current object + rhs
  // Postcondition: the time increases by the value of rhs
  time24 &operator+=(int min);
  // current object = current object + min
  // Precondition:  min must be >= 0
  // Postcondition: the time increases by min minutes

  friend istream &operator>>(istream &istr, time24 &t);
  // input t in the format hh:mm. may omit the leading digit
  // if hours or minutes < 10
  friend ostream &operator<<(ostream &ostr, const time24 &t);
  // output t in the format hh:mm. always include two digits
  // for the minute (e.g. 15:07). hours before 12 use 1 digit
  // and precede the hour by a blank (e.g. " 7:15")
private:
  int hour, minute; // data members
  // utility function sets the hour value in the range 0 to 23
  // and the minute value in the range 0 to 50
  void normalizeTime();
};

#endif // TIME24_H
