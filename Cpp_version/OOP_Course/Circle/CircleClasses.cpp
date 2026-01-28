//
// Created by Vanhuljo on 06/11/2023.
//

#include "CircleClasses.h"

#include <iostream>

using namespace std;

int main() {
  double radius = 0.0;
  cout << "Input the radius of the circle" << endl;
  cin >> radius;

  CircleClasses circle(radius);

  cout << "The area of the circle is " << circle.calculateArea() << endl;
  cout << "The Cirrumstance is " << circle.calculateCircumference() << endl;

  return 0;
}