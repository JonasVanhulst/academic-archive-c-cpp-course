//
// Created by Vanhuljo on 08/11/2023.
//
/*
 * Write a C++ program to dynamically create an array of objects using the new
 * operator.
 * */

#include "memClassArray.h"

#include <iostream>

#define SIZE 10

using namespace std;

int main() {
  memClassArray** array = new memClassArray*[SIZE];

  for (int i = 0; i < SIZE; i++) {
    array[i]->printMessages();
  }

  delete[] array;
  return 0;
}