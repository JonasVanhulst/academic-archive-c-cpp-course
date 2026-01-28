//
// Created by Vanhuljo on 07/11/2023.
//

/*
 * Write a C++ program to create a class called Triangle that has private member
 * variables for the lengths of its three sides. Implement member functions to
 * determine if the triangle is equilateral, isosceles, or scalene.
 * */
#ifndef OOP_LEARNING_TRIANGLE_H
#define OOP_LEARNING_TRIANGLE_H

#include <iostream>

using namespace std;

class Triangle {
 private:
  double sideLengthOne;
  double sideLengthTwo;
  double sideLengthThree;

 public:
  Triangle(double side1, double side2, double side3)
      : sideLengthOne(side1), sideLengthTwo(side2), sideLengthThree(side3) {}

  void Determine() {
    if (sideLengthOne == sideLengthTwo && sideLengthTwo == sideLengthThree) {
      cout << "Triangles are equilateral " << endl;
    } else if (sideLengthOne == sideLengthTwo ||
               sideLengthOne == sideLengthThree ||
               sideLengthTwo == sideLengthThree) {
      cout << "Triangles are isosceles " << endl;
    } else {
      cout << "Triangles are scalene " << endl;
    }
  }
};

#endif  // OOP_LEARNING_TRIANGLE_H
