#include "MovieData.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  MovieData movie1("Halflife 3", "Valve", 9999, 50, 10, 999999);
  MovieData movie2("Phantom", "test", 2017, 482, 231, 53434);
  movie1.print();
  movie2.print();

  system("pause");
  return 1;
}