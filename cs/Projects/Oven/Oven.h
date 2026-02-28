#include <string>

using namespace std;

class Oven {
private:
  int temperature;
  string cookingStyle;

public:
  Oven();
  void setTemperature(int);
  int getTemperature();
  void setCookingStyle(string);
  string getCookingStyle();
  void bake(int, string);
};