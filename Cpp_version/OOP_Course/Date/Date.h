//
// Created by Vanhuljo on 07/11/2023.
//

/*
 * Write a C++ program to implement a class called Date that has private member
 * variables for day, month, and year. Include member functions to set and get
 * these variables, as well as to validate if the date is valid.
 * */
#ifndef OOP_LEARNING_DATE_H
#define OOP_LEARNING_DATE_H

class Date {
 private:
  int Day, Month, Year = 0;

 public:
  Date(int day, int month, int year) : Day(day), Month(month), Year(year) {}

  // Member function to set the date
  void setDate(int d, int m, int y) {
    Day = d;
    Month = m;
    Year = y;
  }

  void setDay(int day) { Day = day; }

  void setMonth(int month) { Month = month; }

  void setYear(int year) { Year = year; }

  int getDay() { return Day; }

  int getMonth() { return Month; }

  int getYear() { return Year; }

  bool isValidDate() const {
    if (Month < 1 || Month > 12) return false;

    if (Day < 1 || Day > 31) return false;

    if ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day > 30)
      return false;

    if (Month == 2) {
      if ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0)) {
        if (Day > 29) return false;
      } else {
        if (Day > 28) return false;
      }
    }
    return true;
  }
};

#endif  // OOP_LEARNING_DATE_H
