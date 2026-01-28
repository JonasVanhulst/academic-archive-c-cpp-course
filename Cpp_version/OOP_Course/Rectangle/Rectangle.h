//
// Created by Vanhuljo on 06/11/2023.
//

/*
 * Write a C++ program to create a class called Rectangle that has private
 * member variables for length and width. Implement member functions to
 * calculate the rectangle's area and perimeter.
 * */

#ifndef OOP_LEARNING_RECTANGLE_H
#define OOP_LEARNING_RECTANGLE_H

class Rectangle {
 private:
  double length;
  double width;

 public:
  Rectangle(double length, double width) : length(length), width(width) {};

  double calculateArea() { return length * width; }

  double calculatePerimeter() { return 2 * (length + width); }
};

#endif  // OOP_LEARNING_RECTANGLE_H
