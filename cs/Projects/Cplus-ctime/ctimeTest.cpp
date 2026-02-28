// This program prints "today's" date
// It also illustrates the use of the time function
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
  time_t epSeconds;  // Seconds since epoch
  tm *pCalendarTime; // Pointer to calendar time
  int wday, mday, cmonth, cyear;
  int hour, minute, second;

  // Array of weekday names
  string wDay[] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                   "Thursday", "Friday", "Saturday"};
  // Array of month names
  string month[] = {"January",   "February", "March",    "April",
                    "May",       "June",     "July",     "August",
                    "September", "October",  "November", "December"};

  epSeconds = time(NULL); // Get seconds since epoch

  pCalendarTime = localtime(&epSeconds); // Convert to local time

  wday = pCalendarTime->tm_wday;
  mday = pCalendarTime->tm_mday;
  cmonth = pCalendarTime->tm_mon;
  cyear = pCalendarTime->tm_year;
  hour = pCalendarTime->tm_hour;
  minute = pCalendarTime->tm_min;
  second = pCalendarTime->tm_sec;

  // Print day of month and day of week
  cout << "Today is " << wDay[wday] << " " << month[cmonth] << " " << mday
       << ", " << 1900 + cyear << endl;

  // Print Time

  cout << "The time Currently is: " << hour << ":" << minute << ":" << second
       << endl;

  system("pause");
  return 0;
}
