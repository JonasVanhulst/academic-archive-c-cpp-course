//
// Created by Vanhuljo on 08/11/2023.
//

#include "Shape.h"

#include <iostream>

using namespace std;

int main() {
  Circle cirle1(7.0);
  Rectangle rectangle1(4.2, 8.0);
  Triangle triangle1(4.0, 4.0, 3.2);

  cout << "Circle: " << endl;
  cout << "Area: " << cirle1.calculatingArea() << endl;
  cout << "Perimeter: " << cirle1.calculatePerimeter() << endl;

  cout << "\nRectangle: " << endl;
  cout << "Area: " << rectangle1.calculatingArea() << endl;
  cout << "Perimeter: " << rectangle1.calculatePerimeter() << endl;

  cout << "\nTriangle: " << endl;
  cout << "Area: " << triangle1.calculatingArea() << endl;
  cout << "Perimeter: " << triangle1.calculatePerimeter() << endl;
  return 0;
}