//
// Created by Vanhuljo on 08/11/2023.
//

/*
 * Write a C++ program to dynamically allocate an array of integers and strings
 * and initialize its elements.
 * */
#include <iostream>

using namespace std;
using std::string;

#define SIZE 9

int main() {
  int* arrayOfInteger = new int[SIZE];

  for (int i = 0; i < SIZE; i++) {
    arrayOfInteger[i] = i + 2;
  }

  string* arrayOfStrings = new string[SIZE];

  for (int i = 0; i < SIZE; i++) {
    arrayOfStrings[i] = "Hello Newbe";
  }

  cout << "Dynamically allocated integer array:" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << arrayOfInteger[i] << " ";
  }
  cout << endl;

  cout << "\nDynamically allocated string array:" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << arrayOfStrings[i] << endl;
  }

  delete[] arrayOfStrings;
  delete[] arrayOfInteger;
  return 0;
}