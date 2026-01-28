//
// Created by Vanhuljo on 09/11/2023.
//

#include "Wolves.h"

#include <stdlib.h>

#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
  srand(time(NULL));
  cout << "Welcome to the game!" << endl;
  list<Civil*> Civilians;

  for (int i = 0; i < 10; i++) {
    cout << "Name: ";
    string userName;
    cin >> userName;
    switch (rand() % 10) {
      case 0:
        Civilians.push_back(new AflaWolves(userName));
        break;
      case 1:
      case 2:
        Civilians.push_back((new Wolves(userName)));
        break;
      default:
        Civilians.push_back(new Civil(userName));
        break;
    }
  }

  for (Civil* b : Civilians) {
    b->nightAction();
  }

  return 0;
}