//
// Created by Vanhuljo on 08/11/2023.
//

/*
 * Write a C++ program to dynamically allocate two two-dimensional arrays of
 * floating values and strings. Initialize its elements.
 * */

#include <iostream>

#define ROWS 3
#define COLOMS 4

using namespace std;
using std::string;

int main() {
  float** arrayOfFloats = new float*[ROWS];

  for (int i = 0; i < ROWS; i++) {
    arrayOfFloats[i] = new float[COLOMS];
  }

  float value = 1.2;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLOMS; j++) {
      arrayOfFloats[i][j] = value;
      value += 1.0;
    }
  }

  string** arrayOfStrings = new string*[ROWS];
  for (int i = 0; i < ROWS; i++) {
    arrayOfStrings[i] = new string[COLOMS];
  }

  // Initialize the elements of the string array
  string element = "M";
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLOMS; j++) {
      arrayOfStrings[i][j] = element;
      element[0] += 1;
    }
  }

  cout << "Dynamically allocated float array:" << endl;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLOMS; j++) {
      cout << arrayOfFloats[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  cout << "Dynamically allocated string array:" << endl;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLOMS; j++) {
      cout << arrayOfStrings[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < ROWS; i++) {
    delete[] arrayOfStrings[i];
    delete[] arrayOfFloats[i];
  }
  delete[] arrayOfStrings;
  delete[] arrayOfFloats;
  return 0;
}