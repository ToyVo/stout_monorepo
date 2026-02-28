// This program demonstrates the Is-A
// relation in inheritance.
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

// Base class
class Dog {
protected:
  double weight;

public:
  Dog(double w) { weight = w; }
  virtual void bark() const {
    cout << "I am a dog weighing " << weight << " pounds." << endl;
  }
};

// A SheepDog is a special type of Dog
class SheepDog : public Dog {
private:
  int numberSheep;

public:
  SheepDog(double w, int nSheep) : Dog(w) { numberSheep = nSheep; }
  virtual void bark() const {
    cout << "I am a sheepdog weighing " << weight << " pounds and guarding "
         << numberSheep << " sheep." << endl;
  }
};

class HoundDog : public Dog {
private:
  string name;
  string adress;

public:
  HoundDog(double w, string n, string a) : Dog(w) {
    name = n;
    adress = a;
  }
  virtual void bark() const {
    cout << "I am a houd dog weighing " << weight << " My name is " << name
         << " I live at " << adress << endl;
  }
};

int main() {
  // Create an array of  dogs
  const int NUM_DOGS = 4;
  Dog *kennel[] = {new Dog(40.5), new SheepDog(45.3, 50), new Dog(24.7),
                   new HoundDog(50, "George", "home")};

  // Walk by each kennel and make the dog bark
  for (int k = 0; k < NUM_DOGS; k++) {
    cout << k + 1 << ": ";
    kennel[k]->bark();
  }

  system("pause");
  return 0;
}