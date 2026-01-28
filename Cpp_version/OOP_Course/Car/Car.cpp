//
// Created by Vanhuljo on 07/11/2023.
//

#include "Car.h"

#include <iostream>

using namespace std;

int main() {
  Car car("BMW", "M3", 1990);

  std::cout << "Company: " << car.getCompany() << std::endl;
  std::cout << "Model: " << car.getModel() << std::endl;
  std::cout << "Year: " << car.getYear() << std::endl;

  car.setCompany("Audi");
  car.setModel("A6");
  car.setYear(2004);

  // Get and display the updated car details
  std::cout << "\nUpdated Company: " << car.getCompany() << std::endl;
  std::cout << "Updated Model: " << car.getModel() << std::endl;
  std::cout << "Updated Year: " << car.getYear() << std::endl;

  return 0;
}
