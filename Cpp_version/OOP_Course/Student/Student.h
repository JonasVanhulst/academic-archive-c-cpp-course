//
// Created by Vanhuljo on 07/11/2023.
//
/*
 * Write a C++ program to implement a class called Student that has private
 * member variables for name, class, roll number, and marks. Include member
 * functions to calculate the grade based on the marks and display the student's
 * information.
 * */
#ifndef OOP_LEARNING_STUDENT_H
#define OOP_LEARNING_STUDENT_H

#include <iostream>

using namespace std;
using std::string;

class Student {
 private:
  string Name;
  string Class;
  int RollNumber;
  double Marks;

 public:
  Student(string studentName, string studenClass, int studentNumber,
          double studentMarks)
      : Name(studentName),
        Class(studenClass),
        RollNumber(studentNumber),
        Marks(studentMarks) {}

  void setPerson(string name) { Name = name; }

  void setClass(string stClass) { Class = stClass; }

  void setRollNumber(int number) { RollNumber = number; }

  void setMarks(double marks) { Marks = marks; }

  string getName() { return Name; }

  string getClass() { return Class; }

  int getRollNumber() { return RollNumber; }

  double getMarks() { return Marks; }

  // Member function to calculate the grade based on marks
  string checkStudentMarks() {
    if (Marks >= 90) {
      return "A+";
    } else if (Marks >= 80) {
      return "A";
    } else if (Marks >= 70) {
      return "B";
    } else if (Marks >= 60) {
      return "C";
    } else {
      return "D";
    }
  }

  // Member function to display student information
  void displayInformation() {
    cout << "\n\nName: " << Name << endl;
    cout << "Class: " << Class << endl;
    cout << "Roll Number: " << RollNumber << endl;
    cout << "Marks: " << Marks << endl;
    cout << "Grade: " << checkStudentMarks() << endl;
  }
};

#endif  // OOP_LEARNING_STUDENT_H
