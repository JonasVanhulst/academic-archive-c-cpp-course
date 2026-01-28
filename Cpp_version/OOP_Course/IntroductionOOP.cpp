// class - describes the structure
// object - a specific example of that structure (instance)
// instance - another name for object
// instantiating - creating an object from a class
// data members - variables
// methods - functions
// parent class (base class) - inherited FROM
// child class (derived class) - does the inheriting

// abstraction -- a concept where you make something easy by hiding the complicated stuff
// encapsulation -- granting access to private data only through controlled public interfaces
// inheritance -- we can create derived classes that inherit properties from their parent classes
// polymorphism -- we can treat multiple different objects as their base object type

#include <iostream>

using namespace std;
using std::string;

// Abstract class
class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

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
class Employee : AbstractEmployee {
private:
    string Company;
    int Age;

protected:
    string Name;

public:
    void setName(string name) {
        Name = name;
    }

    string getName() {
        return Name;
    }

    void setCompany(string company) {
        Company = company;
    }

    string getCompany() {
        return Company;
    }

    void setAge(int age) {
        if (age >= 18)
            Age = age;
    }

    int getAge() {
        return Age;
    }

    void IntroduceYourself() {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }

    // Constructor
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    void AskForPromotion() {
        if (Age > 30)
            cout << Name << " got promoted!" << endl;
        else
            cout << Name << " , sorry NO promotion for you!" << endl;
    }

    virtual void Work() {
        cout << Name << " is checking email, task backlog, performing tasks..." << endl;
    }
};

// inheritance class
class Developer : public Employee {
public:
    string FavProgrammingLanguage;

    Developer(string name, string company, int age, string favProgrammingLanguage) : Employee(name, company, age) {
        FavProgrammingLanguage = favProgrammingLanguage;
    };

    void FixBug() {
        cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
    }

    void Work() override {
        cout << Name << " is writing " << FavProgrammingLanguage << " Code" << endl;
    }
};

class Teacher : public Employee {
public:
    string Subject;

    void PrepareLesson() {
        cout << Name << " is preparing " << Subject << " lesson " << endl;
    }

    Teacher(string name, string company, int age, string subject) : Employee(name, company, age) {
        Subject = subject;
    }

    void Work() {
        cout << Name << " is teaching " << Subject << endl;
    }
};

int main() {
    // The most common use of polymorphism is when a parent class reference is used to refer to a child class object
    Developer d = Developer("Bryan", "PXL", 23, "React-Native");
    Teacher t = Teacher("Koen", "VIA", 43, "Electronics");

    Employee *e1 = &d;
    Employee *e2 = &t;

    e1->Work();
    e2->Work();

    return 0;
}