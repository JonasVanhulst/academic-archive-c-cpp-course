//
// Created by Vanhuljo on 07/11/2023.
//

#include "Date.h"

#include <iostream>

using namespace std;

int main() {
  Date date(0, 0, 0);

  // Set the date
  int day, month, year;
  cout << "Input day: ";
  cin >> day;
  cout << "Input month: ";
  cin >> month;
  cout << "Input year: ";
  cin >> year;

  date.setDate(day, month, year);

  if (date.isValidDate()) {
    cout << "You entered a valid date" << endl;
  } else {
    cout << "Your entered a wrong date: " << date.getDay() << "/"
         << date.getMonth() << "/" << date.getYear() << endl;
  }

  return 0;
}