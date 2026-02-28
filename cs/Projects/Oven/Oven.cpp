#include "Oven.h"
#include <string>

using namespace std;

Oven::Oven() {
  temperature = 100;
  cookingStyle = "Slow";
}

void Oven::setTemperature(int n) { temperature = n; }

int Oven::getTemperature() { return temperature; }

void Oven::setCookingStyle(string s) { cookingStyle = s; }

string Oven::getCookingStyle() { return cookingStyle; }

void Oven::bake(int n, string s) {
  setTemperature(n);
  setCookingStyle(s);
}