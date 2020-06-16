#include <iostream>
#include "test1.h"
#include "test02.h"
using namespace std;

void printFriend(){
  TestTemplate<> t1(0), t2(1);
  t1.setT1(20);
  t2.setT1(20);
  if(t1 == t2)
    cout << "t1 is equal to t2" << endl;
  else
    cout << "t1 is not  equal to t2" << endl;
}

