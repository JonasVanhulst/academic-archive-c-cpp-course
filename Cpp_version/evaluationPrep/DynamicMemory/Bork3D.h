//
// Created by Vanhuljo on 10/11/2023.
//

#ifndef CPP_EVALUATION_BORK3D_H
#define CPP_EVALUATION_BORK3D_H

#include <iostream>

using namespace std;

class Bork3D {
 private:
  float memValues;

 public:
  Bork3D() = default;

  void setValue(float value) { memValues = value; }

  float getValue() { return memValues; }
};

#endif  // CPP_EVALUATION_BORK3D_H
