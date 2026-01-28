//
// Created by Vanhuljo on 08/11/2023.
//
/*
 * Write a C++ program to dynamically create an object of a class using the new
 * operator.
 * */

#include "memClass.h"

#include <iostream>

using namespace std;

int main() {
  memClass* memory = new memClass;

  memory->showMessage();

  delete memory;

  return 0;
}