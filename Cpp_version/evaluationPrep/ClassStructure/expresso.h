//
// Created by Vanhuljo on 10/11/2023.
//

#ifndef CPP_EVALUATION_EXPRESSO_H
#define CPP_EVALUATION_EXPRESSO_H

#include "coffee.h"

class expresso : public coffee {
 public:
  // constructor
  expresso(string customer) : coffee(customerID) {}

  // member function
  void drink(double liter) const override;

  // destructor
  ~expresso();
};

#endif  // CPP_EVALUATION_EXPRESSO_H
