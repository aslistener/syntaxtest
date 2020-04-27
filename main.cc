#include "test_static.h"
#include <assert.h>

int main(int argc, char *argv[]) {
	A a;
  A::print(a);
  PRINT_VAL_MSG(11, "hello, world");
  return 0;
}