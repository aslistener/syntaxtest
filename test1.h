#pragma once

#include <iostream>
#include <vector>
using namespace std;

template<typename T1 = int>
class TestTemplate
{
public:
 TestTemplate(int id): id_(id){}
 ~TestTemplate(){}

  void setT1(const T1 &t1){t1_ = t1; }
		
  bool equal(const TestTemplate &other) {
	  return other.t1_ == t1_;	 
  }

  friend bool operator==(TestTemplate &cur,
    const TestTemplate &other){
    cout << "friend function is called"<<endl;
    return cur.equal(other);
  }

private:
  int id_;  
  T1 t1_;
};


struct Test1{
  double x;
  char c;
  int i;
  double d;
};
struct alignas(8) Test2{
  double x;
  char c;
  int i;
  double d;
};
struct alignas(16) Test3{
  double x;
  char c;
  int i;
  double d;
};

static void printSize(){
  cout << "sizeof no align: " << sizeof(Test1) << endl;
  cout << "sizeof align 8: " << sizeof(Test2) << endl;
  cout << "sizeof align 16: " << sizeof(Test3) << endl;

}

struct A {
  A() = default;
  A(int i): mi(i){}
  A(const A&) = delete;
  A& operator = (const A&) = delete;
  A(A &&a) :mi(a.mi){a.mi = 0; }
  A& operator = (A&&) = default;

  int mi = 0;
};

static void TestNonCopyable() {
	A a1(10);
	std::vector<A> vec;
	//vec.push_back(a1);
	cout << "after move: " << a1.mi << endl;
	
}


