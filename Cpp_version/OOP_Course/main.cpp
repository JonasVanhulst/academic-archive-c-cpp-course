#include <iostream>

using namespace std;
using std::string;

/*
 *
 * Classes
 *
 * Class is default private
 *
 * private => everything is hidden
 * public => accessing outside class
 * protected => bewteen private and public
 *
 */
class Employee {
 private:
  string Name;
  string Company;
  int Age;

 public:
  void IntroduceYourself() {
    cout << "Name - " << Name << endl;
    cout << "Company - " << Company << endl;
    cout << "Age - " << Age << endl;
  }

  Employee(string name, string company, int age) {
    Name = name;
    Company = company;
    Age = age;
  }
};

int main() {
  Employee employee1 =
      Employee("BART", "PXL", 25);  // creating variable from the class
  employee1.IntroduceYourself();

  Employee employee2 = Employee("Jhon", "Amazon", 34);
  employee2.IntroduceYourself();

  return 0;
}
