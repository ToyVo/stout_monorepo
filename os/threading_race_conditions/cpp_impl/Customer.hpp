//
// Created by Collin Diekvoss on 4/11/20.
//

#ifndef CPP_IMPL_CUSTOMER_HPP
#define CPP_IMPL_CUSTOMER_HPP

#include <sstream>
#include <string>

class Customer {
private:
  std::string ID;
  double balance;

public:
  Customer() {
    ID = "-";
    balance = -1;
  };
  Customer(std::string iD, double bal) {
    ID = iD;
    balance = bal;
  };
  std::string getID() const { return ID; };
  void setID(std::string iD) { ID = iD; };
  double getBalance() const { return balance; };
  void setBalance(double bal) { balance = bal; };
  std::string str() {
    std::ostringstream oss;
    oss << "Customer [ID=" << ID << ", balance=" << balance << "]";
    return oss.str();
  };
};

#endif // CPP_IMPL_CUSTOMER_HPP
