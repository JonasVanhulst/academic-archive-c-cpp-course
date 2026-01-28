//
// Created by Vanhuljo on 10/11/2023.
//

#ifndef CPP_EVALUATION_COFFEE_H
#define CPP_EVALUATION_COFFEE_H

#include <iostream>

using namespace std;
using std::string;

class coffee {
 protected:
  // member variable
  const string customerID;

 public:
  // constructor
  coffee(string customer) : customerID(customer) {};

  // member function
  virtual void drink(double liter) const = 0;

  // destructor
  ~coffee();
};

#endif  // CPP_EVALUATION_COFFEE_H
