//
// Created by Vanhuljo on 10/11/2023.
//

#include "cappuccino.h"

void cappuccino::drink(double liter) const {
  if (liter > 0.01) {
    cout << customerID << "is instantly awake" << endl;
  }
}