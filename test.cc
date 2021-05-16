#include <iostream>
#include <thread>
#include <map>

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

void TestSharedPointer(){
  std::weak_ptr<int> gw;
  auto observe = [&gw](){
    std::cout << "refcount: " << gw.use_count() << endl;
    if (auto spt = gw.lock()) { 
	  // Has to be copied into a shared_ptr before usage
	  std::cout << "refcount after lock: " << gw.use_count() << endl;
	  std::cout << *spt << "\n";
    }
    else {
      std::cout << "gw is expired\n";
    }
  };
  {
    auto sp = std::make_shared<int>(42);
    gw = sp;
    observe();
  }
  observe();
}

void TestMemoryLeak() {
	std::thread t([](){
		static int i = 0;
    for(int i = 0; i < 100; i++){
	    int *x = new int(++i);
      this_thread::sleep_for(10ms);
			cout << "the " << *x << " time allocation" << endl;
    }
  });
	t.join();
}

void TestStringMap() {
  std::cout << "------------testing for char array key "
      << std::endl;
  std::map<const char*, const char *> arraymap;
  arraymap["h1"] = "hello1";
  arraymap["h2"] = "hello2";
  arraymap["h3"] = "hello3";
  arraymap["h4"] = "hello4";
  for(auto &pair: arraymap) 
    std::cout << pair.first
        << "  stores " << arraymap[pair.first] << std::endl; 

  std::cout << "------------testing for std string key "
      << std::endl;
  std::map<std::string, const char *> stringmap;
  stringmap[std::string("h1")] = "hello1";
  stringmap[std::string("h2")] = "hello2";
  stringmap[std::string("h3")] = "hello3";
  stringmap[std::string("h4")] = "hello4";

  for(auto &pair: stringmap) 
    std::cout << pair.first
        << "  stores " << stringmap[pair.first] << std::endl; 
}

void TestStaticCastDeallocatedMemory() {
  class A{};
  class B: public A{};
  A* ptr = new B;
  delete ptr;
  if(static_cast<B*>(ptr)) {
    printf("static cast can not find dangling pointer\n");
  } else {
    printf("static cast find dangling pointer\n");
  }
}
