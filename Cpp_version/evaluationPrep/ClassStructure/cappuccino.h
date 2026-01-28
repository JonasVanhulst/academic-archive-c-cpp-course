//
// Created by Vanhuljo on 10/11/2023.
//

#ifndef CPP_EVALUATION_CAPPUCCINO_H
#define CPP_EVALUATION_CAPPUCCINO_H

#include "coffee.h"

class cappuccino : public coffee {
 public:
  // constructor
  cappuccino(string customer) : coffee(customerID) {}

  // member function
  void drink(double liter) const override;

  // destructor
  ~cappuccino();
};

#endif  // CPP_EVALUATION_CAPPUCCINO_H
