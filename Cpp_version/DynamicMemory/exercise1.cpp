//
// Created by Vanhuljo on 08/11/2023.
//

/*
 * Write a C++ program to dynamically allocate an integer, a character and a
 * string and assign a value to them.
 * */

#include <iostream>

using namespace std;
using std::string;

int main() {
  // Dynamically allocate an integer
  int* dynamicInt = new int;
  *dynamicInt = 20;

  // Dynamically allocate a character
  char* dynamicChar = new char;
  *dynamicChar = 'C';

  // Dynamically allocate a string
  string* dynamicString = new string;
  *dynamicString = "C++ Dynamically allocated string.";

  // Display the values
  cout << "Dynamically allocated integer: " << *dynamicInt << endl;
  cout << "Dynamically allocated character: " << *dynamicChar << endl;
  cout << "Dynamically allocated string: " << *dynamicString << endl;

  // Deallocate the memory
  delete dynamicInt;
  delete dynamicChar;
  delete dynamicString;

  return 0;
}