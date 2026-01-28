//
// Created by Vanhuljo on 07/11/2023.
//

#include "Employee.h"

#include <iostream>

using namespace std;
using std::string;

int main() {
  string employeeName;
  int employeeID = 0;
  double employeeSalary = 0.0;

  cout << "Enter your Name: ";
  cin >> employeeName;
  cout << "Enter your ID: ";
  cin >> employeeID;
  cout << "Enter your salary ";
  cin >> employeeSalary;

  Employee employee(employeeName, employeeID, employeeSalary);

  cout << "Initial salary: " << employee.getSalary() << endl;

  double performanceRating;
  cout << "Input performance rating (0.0-1.2): ";
  cin >> performanceRating;

  employee.calculateSalary(performanceRating);

  cout << "Updated salary: " << employee.getSalary() << endl;

  return 0;
}