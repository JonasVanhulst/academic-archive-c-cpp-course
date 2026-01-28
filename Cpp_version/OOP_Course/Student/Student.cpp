//
// Created by Vanhuljo on 07/11/2023.
//

#include "Student.h"

#include <iostream>

using namespace std;
using std::string;

int main() {
  string studentName;
  string sClass;
  int rollNum;
  double studentMarks;
  cout << "Student details: ";
  cout << "\nName: ";
  getline(std::cin, studentName);

  cout << "Class: ";
  getline(std::cin, sClass);

  cout << "Roll number: ";
  cin >> rollNum;

  cout << "Marks (0-100): ";
  cin >> studentMarks;

  Student student1(studentName, sClass, rollNum, studentMarks);

  student1.checkStudentMarks();
  student1.displayInformation();

  return 0;
}