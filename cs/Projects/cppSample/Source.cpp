// This program includes C++ basic programming examples
#include <ctime>
#include <iomanip> // Header file needed to use setw
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define PI 3.1415926535897932384626433832795

void payCal();
void displayDataTypes();
void initialize();
int rectArea(int len, int wid);
float circleArea(float radi);
void setwFunc();
void setPrecision();
void randDemon();

int main() {
  payCal();

  displayDataTypes();

  initialize();

  int length, width, area;
  cout << "This program calculates the area of a rectangle.\n";

  // Have the user input the rectangle's length and width
  cout << "Enter the length and width of the rectangle ";
  cout << "separated by a space.\n";
  cin >> length >> width;

  area = rectArea(length, width);
  cout << "The area of the rectangle is " << area << endl;

  float carea, radius;
  cout << "This program calculates the area of a circle.\n";

  // Get the radius
  cout << "What is the radius of the circle? ";
  cin >> radius;

  // Compute and display the area
  carea = circleArea(radius);
  cout << "The area is " << carea << endl;

  setwFunc();
  setPrecision();
  randDemon();

  system("pause");
  return 0;
}

// This program calculates the user's pay.
void payCal() {
  double hours, rate, pay;

  // Get the number of hours worked.
  cout << "How many hours did you work? ";
  cin >> hours;

  // Get the hourly pay rate.
  cout << "How much do you get paid per hour? ";
  cin >> rate;

  // Calculate the pay.
  pay = hours * rate;

  // Display the pay.
  cout << "You have earned $" << pay << endl;
}

// This program displays the size of various data types.
void displayDataTypes() {
  long double salary;

  cout << "The size of an integer is " << sizeof(int);
  cout << " bytes.\n";
  cout << "The size of a long integer is " << sizeof(long);
  cout << " bytes.\n";
  cout << "An apple can be eaten in " << sizeof(salary);
  cout << " bytes!\n";
}

// This program shows variable initialization.
void initialize() {
  string month = "February"; // month is initialized to "February"
  int year,                  // year is not initialized
      days = 28;             // days is initialized to 28

  year = 2007; // Now year is assigned a value

  cout << "In " << year << " " << month << " had " << days << " days.\n";
}

// This program calculates and displays the area of a rectangle.
int rectArea(int len, int wid) {
  // Compute and display the area
  return len * wid;
}

// This program calculates the area of a circle. The formula for the
// area of a circle is PI times the radius squared. PI is 3.14159.
float circleArea(float radi) {
  // Compute and display the area
  return PI * pow(radi, 2);
}

// This program demonstrates the setw manipulator
// being used with variables of various data types.
void setwFunc() {
  int intValue = 3928;
  double doubleValue = 91.5;
  string stringValue = "Jill Q. Jones";

  cout << "(" << setw(5) << intValue << ")" << endl;
  cout << "(" << setw(8) << doubleValue << ")" << endl;
  cout << "(" << setw(16) << stringValue << ")" << endl;
}

// This program demonstrates how the setprecision manipulator
// affects the way a floating-point value is displayed.
void setPrecision() {
  double number1 = 132.364, number2 = 26.91;
  double quotient = number1 / number2;

  cout << quotient << endl;
  cout << setprecision(5) << quotient << endl;
  cout << setprecision(4) << quotient << endl;
  cout << setprecision(3) << quotient << endl;
  cout << setprecision(2) << quotient << endl;
  cout << setprecision(1) << quotient << endl;
}

// This program demonstrates using the C++ time function
// to provide a "seed" for the random number generator.
void randDemon() {
  unsigned seed; // Random generator seed

  // Use the time function to get a "seed" value for srand
  seed = time(0);
  srand(seed);

  // Now generate and print three random numbers
  cout << rand() << " ";
  cout << rand() << " ";
  cout << rand() << endl;
}