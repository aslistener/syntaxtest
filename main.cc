#include "test_static.h"
#include "test02.h"
#include "functions.h"


#include <assert.h>

#define TEST111

#define TESTINT 100

#define VALUE_TO_STRING(x) #x
#define VALUE(x) VALUE_TO_STRING(x)
#define VAR_NAME_VALUE(var) #var "="  VALUE(var)


#pragma message(VAR_NAME_VALUE(TESTINT))

void print() {
#ifdef TEST111
std::cout << "#if is equal to #ifdef " << std::endl;
#else
std::cout << "#if is not equal to #ifdef " << std::endl;
#endif

}




int main(int argc, char *argv[]) {
  //A a;
  //A::print(a);
  //PRINT_VAL_MSG(11, "hello, world");
  //TestSharedPointer();

  //print();
//	TestMemoryLeak();
//  TestStringMap();;

//  TestStaticCastDeallocatedMemory();


  TestCtorDtor();
  return 0;
}
