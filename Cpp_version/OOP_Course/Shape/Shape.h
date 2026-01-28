//
// Created by Vanhuljo on 08/11/2023.
//
/*
 * Write a C++ program to implement a class called Shape with virtual member
 * functions for calculating area and perimeter. Derive classes such as Circle,
 * Rectangle, and Triangle from the Shape class and override virtual functions
 * accordingly.
 * */

#ifndef OOP_LEARNING_SHAPE_H
#define OOP_LEARNING_SHAPE_H

#include <cmath>

const double PI = 3.14159;

class Shape {
 public:
  virtual double calculatingArea() const = 0;

  virtual double calculatePerimeter() const = 0;
};

class Circle : public Shape {
 private:
  double Radius;

 public:
  Circle(double rad) : Radius(rad) {};

  double calculatingArea() const override { return PI * pow(Radius, 2); }

  double calculatePerimeter() const override { return 2 * PI * Radius; }
};

class Rectangle : public Shape {
 private:
  double width, length = 0.0;

 public:
  Rectangle(double wid, double len) : width(wid), length(len) {}

  double calculatingArea() const override { return width * length; }

  double calculatePerimeter() const override { return 2 * (length + width); }
};

class Triangle : public Shape {
 private:
  double side1, side2, side3 = 0.0;

 public:
  Triangle(double firstSide, double secondSide, double thirdSide)
      : side1(firstSide), side2(secondSide), side3(thirdSide) {}

  double calculatingArea() const override {
    double s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
  }

  double calculatePerimeter() const override { return side1 + side2 + side3; }
};

#endif  // OOP_LEARNING_SHAPE_H
