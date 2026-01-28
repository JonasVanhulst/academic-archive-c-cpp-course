//
// Created by Vanhuljo on 10/11/2023.
//

#ifndef CPP_EVALUATION_CAFEGRAND_H
#define CPP_EVALUATION_CAFEGRAND_H

#include "coffee.h"

class cafeGrand : public coffee {
 public:
  // constructor
  cafeGrand(string customerName) : coffee(customerID) {}

  // member function
  void drink(double liter) const override;

  // destructor
  ~cafeGrand();
};

#endif  // CPP_EVALUATION_CAFEGRAND_H
