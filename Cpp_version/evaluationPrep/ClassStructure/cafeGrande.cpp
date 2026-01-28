//
// Created by Vanhuljo on 10/11/2023.
//

#include "cafeGrande.h"

void cafeGrand::drink(double liter) const {
  if (liter > 0.2) {
    cout << customerID << "gets warm" << endl;
  }
}