#pragma once
#include <iostream>
using namespace std;

#define PRINT_VAL(value) PRINT_VAL_MSG(value,"")
#define PRINT_VAL_MSG(value, message) cout << #value" : " << value <<", " message



// test for static member function's privilege
// static member function has integral access of a class 
class A{
public:
    static void print(A &a) { cout << "a is " << a.a << endl; }

private:
  int a = 0;
};

