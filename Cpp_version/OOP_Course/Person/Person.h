//
// Created by Vanhuljo on 06/11/2023.
//

/*
 *  Write a C++ program to create a class called Person that has private member
 * variables for name, age and country. Implement member functions to set and
 * get the values of these variables.
 * */

#ifndef OOP_LEARNING_PERSON_H
#define OOP_LEARNING_PERSON_H

#include <iostream>

using std::string;

class Person {
 private:
  string Name;
  string Country;
  int Age;

 public:
  void setName(string name) { Name = name; }

  string getName() { return Name; }

  void setCountry(string country) { Country = country; }

  string getCountry() { return Country; }

  void setAge(int age) { Age = age; }

  int getAge() { return Age; }
};

#endif  // OOP_LEARNING_PERSON_H
