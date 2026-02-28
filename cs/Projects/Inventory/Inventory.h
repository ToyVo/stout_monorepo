class Inventory {
private:
  int itemNumber;
  int quantity;
  double cost;

public:
  Inventory();
  Inventory(int, int, double);
  void setItemNumber(int);
  void setQuantity(int);
  void setCost(double);
  int getItemNumber();
  int getQuantity();
  double getCost();
  void getTotalCost();
};