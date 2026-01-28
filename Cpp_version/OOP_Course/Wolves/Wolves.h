//
// Created by Vanhuljo on 09/11/2023.
//

#ifndef OOP_LEARNING_WOLVES_H
#define OOP_LEARNING_WOLVES_H

#include <iostream>
#include <string>

using namespace std;

class Civil {
 protected:
  const string Name;

 public:
  Civil(string name) : Name(name) {}

  virtual void nightAction() { cout << Name << " is sleeping." << endl; }
};

class Wolves : public Civil {
 public:
  Wolves(string name) : Civil(name) {}

  void nightAction() { cout << Name << " is eating!" << endl; }
};

class AflaWolves : public Wolves {
 public:
  AflaWolves(string name) : Wolves(name) {}

  void nightAction() { cout << Name << " is eating more!!" << endl; }
};

#endif  // OOP_LEARNING_WOLVES_H
