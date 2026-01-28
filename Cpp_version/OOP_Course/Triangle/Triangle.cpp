//
// Created by Vanhuljo on 07/11/2023.
//

#include "Triangle.h"

#include <iostream>

using namespace std;

int main() {
  double side1, side2, side3 = 0.0;

  cout << "Give your first value " << endl;
  cin >> side1;
  cout << "Give your second value " << endl;
  cin >> side2;
  cout << "Give your third value " << endl;
  cin >> side3;

  Triangle triangle(side1, side2, side3);
  triangle.Determine();

  return 0;
}