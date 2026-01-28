#include <iostream>

using namespace std;

// tip alle function public en variabele private
class Engine {  // base class
 public:
  Engine() {}
  virtual ~Engine() {}
  void bla() {}
  virtual void f() = 0;  // Pure (=0) virtual function --> ABSTRACT base class
  int getSize() const;

  // private:
  int size;  // variabele
};

class Car {  // object composition class --> Y "has" X
 public:
  Engine* b;  // object
};

class DieselEngine : public Engine {  // inheritance --> Z "is" X
 public:
  ~DieselEngine() {};
  int c;
  virtual void f();
};

int main() {
  int a;              // variabele
                      // Engine aa; // object
  Car aaa;            // object
  DieselEngine aaaa;  // object

  aaaa.size = 42;
  aaaa.c = 42;

  Car d;
  d.b = new DieselEngine();
  d.b->size = 42;
}
