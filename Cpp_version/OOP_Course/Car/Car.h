//
// Created by Vanhuljo on 07/11/2023.
//

/*
 * Write a C++ program to create a class called Car that has private member
 * variables for company, model, and year. Implement member functions to get and
 * set these variables.
 * */

#ifndef OOP_LEARNING_CAR_H
#define OOP_LEARNING_CAR_H

#include <iostream>

using namespace std;
using std::string;

class Car {
 private:
  string Company;
  string Model;
  int Year;

 public:
  Car(string company, string model, int year)
      : Company(company), Model(model), Year(year) {}

  void setCompany(string company) { Company = company; }

  void setYear(int year) { Year = year; }

  void setModel(string model) { Model = model; }

  string getCompany() { return Company; }

  string getModel() { return Model; }

  int getYear() { return Year; }
};

#endif  // OOP_LEARNING_CAR_H
