//
// Created by Vanhuljo on 06/11/2023.
//

#include "Person.h"

#include <iostream>

using namespace std;

int main() {
  Person person;

  person.setName("Koen");
  person.setAge(12);
  person.setCountry("Tienen");

  cout << "Name: " << person.getName() << endl;
  cout << "Age: " << person.getAge() << endl;
  cout << "Country: " << person.getCountry() << endl;

  return 0;
}
