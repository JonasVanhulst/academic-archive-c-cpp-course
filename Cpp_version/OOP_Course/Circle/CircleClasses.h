//
// Created by Vanhuljo on 06/11/2023.
//

/*
 * Write a C++ program to implement a class called Circle that has private
 * member variables for radius. Include member functions to calculate the
 * circle's area and circumference.
 * */

#ifndef OOP_LEARNING_CIRCLECLASSES_H
#define OOP_LEARNING_CIRCLECLASSES_H

#include <cmath>
#include <iostream>

using namespace std;

const double PI = 3.14159;

class CircleClasses {
 private:
  double radius;

 public:
  // Constructor
  CircleClasses(double rad) : radius(rad) {}

  double calculateArea() { return PI * pow(radius, 2); }

  double calculateCircumference() { return 2 * PI * radius; }

  ~CircleClasses() { cout << "destroyed" << endl; }
};

#endif  // OOP_LEARNING_CIRCLECLASSES_H
