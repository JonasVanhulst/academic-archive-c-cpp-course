//
// Created by Vanhuljo on 08/11/2023.
//

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream inputFile("singleWrite.txt");

  if (inputFile.is_open()) {
    string line;
    while (getline(inputFile, line)) {
      cout << line << endl;
    }

  } else {
    cout << "Failed to create the file." << endl;
  }

  return 0;
}