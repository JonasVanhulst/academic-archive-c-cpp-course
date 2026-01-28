//
// Created by Vanhuljo on 06/11/2023.
//

#include "Rectangle.h"

#include <iostream>

using namespace std;

int main() {
  double lenght, width;

  cout << "Give the length: " << endl;
  cin >> lenght;
  cout << "Give the width: " << endl;
  cin >> width;

  Rectangle rectangle(lenght, width);

  cout << "The Area is " << rectangle.calculateArea() << endl;
  cout << "The Perimeter is " << rectangle.calculatePerimeter() << endl;

  return 0;
}