//
// Created by Vanhuljo on 07/11/2023.
//

/*
 *Write a C++ program to implement a class called Employee that has private
 * member variables for name, employee ID, and salary. Include member functions
 * to calculate and set salary based on employee performance.
 * */
#ifndef OOP_LEARNING_EMPLOYEE_H
#define OOP_LEARNING_EMPLOYEE_H

#include <iostream>

using namespace std;
using std::string;

class Employee {
 private:
  string Name;
  int ID;
  double Salary;

 public:
  Employee(string name, int emplId, double money)
      : Name(name), ID(emplId), Salary(money) {}

  void setSalary(double salary) { Salary = salary; }

  double getSalary() { return Salary; }

  string getName() { return Name; }

  void calculateSalary(double performanceRating) {
    if (performanceRating >= 0.0 && performanceRating <= 1.4) {
      Salary *= performanceRating;
    } else {
      std::cout << "Invalid performance rating. Salary remains unchanged."
                << std::endl;
    }
  }
};

#endif  // OOP_LEARNING_EMPLOYEE_H
