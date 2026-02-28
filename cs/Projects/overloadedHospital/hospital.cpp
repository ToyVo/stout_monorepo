#include <iomanip>
#include <iostream>

using namespace std;

char getResponce();
double calcBill(int days, double rate, double service, double medication);
double calcBill(double service, double medication);
void validate(double &num);
void validate(int &num);

void main() {
  char InOrOut;
  int days;
  double rate, services, medication;

  cout << fixed << showpoint << setprecision(2);

  cout << "Is the paitient an in(I) or and out(O) patient" << endl;
  InOrOut = getResponce();

  switch (InOrOut) {
  case 'o':
  case 'O':
    cout << "What is the charge for hospital services: " << endl;
    cin >> services;
    validate(services);
    cout << "What is the medication cost: " << endl;
    cin >> medication;
    validate(medication);
    cout << "total bill is: " << calcBill(services, medication) << endl;
    break;
  case 'i':
  case 'I':
    cout << "How many days spent in the hospital: " << endl;
    cin >> days;
    validate(days);
    cout << "How much is the daily rate: " << endl;
    cin >> rate;
    validate(rate);
    cout << "What is the charge for hospital services: " << endl;
    cin >> services;
    validate(services);
    cout << "What is the medication cost: " << endl;
    cin >> medication;
    validate(medication);
    cout << "total bill is: " << calcBill(days, rate, services, medication)
         << endl;
    break;
  }

  system("pause");
  return;
}

char getResponce() {
  char letter;
  cin >> letter;

  while (letter != 'O' && letter != 'o' && letter != 'I' && letter != 'i') {
    cout << "Enter O or I: ";
    cin >> letter;
  }
  return letter;
}

double calcBill(int days, double rate, double service, double medication) {
  return (days * rate) + service + medication;
}

double calcBill(double service, double medication) {
  return service + medication;
}

void validate(double &num) {
  while (num <= 0) {
    cout << "enter a number greater than 0" << endl;
    cin >> num;
  }
}

void validate(int &num) {
  while (num <= 0) {
    cout << "enter a number greater than 0" << endl;
    cin >> num;
  }
}