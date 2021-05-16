#include "functions.h"

#include <iostream>

using std::cout;
using std::endl;

#define printMsg(msg) cout << __FUNCTION__ << " called , " << msg << endl
#define fprint printMsg("")

struct A {
  A() {
    fprint;
  }
  ~A() {
    fprint;
  }
};

struct B {
  B() {
    fprint;
  }
  ~B(){
    fprint;
  }
  A a;
};

struct C {
  C() {
    fprint;
  }
  ~C(){
    fprint;
  }
};

struct D: public B {
  D() {
    fprint;
  }
  ~D() {
    fprint;
  }
};

void TestCtorDtor() {
  printMsg("test for constructor and destructor");
  C c;
  D d;   
}