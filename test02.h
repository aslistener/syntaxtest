#pragma once

#include <iostream>
using namespace std;

/*
 * test whether the machine is big endian
 * */
static void CheckIsBigEndian(){
  int x = 255;
  char *px = (char *)&x;
  if(!px[0] && !px[1] && !px[2] && px[3]) {
    cout << "sw64 is big endian" << endl;
  } else if(px[0] && !px[1] && !px[2] && !px[3]) {
    cout << "sw64 is little endian" << endl; 
  } else {
  }
}

/*
static void CheckIsBigEndian2(){
  union alignas(4) TestIsBigEndian{
    int x;
    char b;
  };
  TestIsBigEndian t1;
  t1.x = 0;
  t1.x = 0x41000042;

  if(t1.b=='A') {
    cout << "sw64 is little endian" << endl;
  } else {
    cout << "sw64 is big endian" << endl; 
  }
}
*/
