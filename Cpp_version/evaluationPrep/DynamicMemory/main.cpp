//
// Created by Vanhuljo on 10/11/2023.
//

#include <iostream>

#include "Bork3D.h"

using namespace std;

int main() {
  int arraySize = 0;

  float firstArray;

  cout << "[User] - Enter a positive number of type int: " << endl;
  cin >> arraySize;
  cout << endl;

  Bork3D* arrayOfFloat = new Bork3D[arraySize];

  for (int i = 0; i < arraySize; i++) {
    cin >> firstArray;
    arrayOfFloat[i].setValue(firstArray);
  }

  for (int i = 0; i < arraySize; i++) {
    cout << "[arrayValue]: " << arrayOfFloat[i].getValue() << endl;
  }

  delete[] arrayOfFloat;

  return 0;
}