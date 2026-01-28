//
// Created by Vanhuljo on 10/11/2023.
//

#include <iostream>
#include <list>

#include "cafeGrande.h"
#include "cappuccino.h"
#include "coffee.h"
#include "expresso.h"

using namespace std;
using std::string;

int main() {
  list<coffee*> coffeeTypes;

  coffeeTypes.push_back(new expresso("Jonas"));
  coffeeTypes.push_back(new cafeGrand("JonasV"));
  coffeeTypes.push_back(new cappuccino("JonasVanhulst"));

  for (coffee* kopje : coffeeTypes) {
    kopje->drink(0.2);
  }

  return 0;
}