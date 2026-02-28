class Box {
private:
  double x;
  double y;
  int width;
  int height;

public:
  Box(double, double, int, int);
  void move(double, double);
  int area();
  double getMinX();
  double getMaxX();
  double getMinY();
  double getMaxY();
  bool intersects(Box);
};