//
// Created by Vanhuljo on 08/11/2023.
//

/*
 * Write a C++ program to dynamically allocate memory for a character and a
 * string. Input a character and a string from the user.
 * */

#include <iostream>

using namespace std;
using std::string;

int main() {
  char* charMemory = new char;
  string* stringMemory = new string;

  cout << "Give me a character: ";
  cin >> *charMemory;

  cout << "Give me a string: ";
  cin.ignore();
  getline(cin, *stringMemory);

  cout << "Given character: " << *charMemory << endl;
  cout << "Given string: " << *stringMemory << endl;

  delete charMemory;
  delete stringMemory;
  return 0;
}