//
// Created by Vanhuljo on 08/11/2023.
//

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ofstream outputFile("singleWrite.txt");

  if (outputFile.is_open()) {
    // Write some text into the file
    outputFile << "C++ is a high-level, general-purpose programming language "
                  "created by Danish computer scientist Bjarne Stroustrup. \n";
    outputFile << "First released in 1985 as an extension of the C programming "
                  "language, it has since expanded significantly over time. \n";
    outputFile << "Modern C++ currently has object-oriented, generic, and "
                  "functional features, in addition to facilities for "
                  "low-level memory manipulation.\n";
    outputFile << "It is almost always implemented in a compiled language.\n";
    outputFile
        << "Many vendors provide C++ compilers, including the Free Software "
           "Foundation, LLVM, Microsoft, Intel, Embarcadero, Oracle, and IBM.";

    // Close the file
    outputFile.close();

    cout << "Text has been written to the file." << endl;
  } else {
    cout << "Failed to create the file." << endl;
  }

  return 0;
}