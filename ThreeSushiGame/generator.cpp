#include "testlib/testlib.h"
#include <iostream>

int main(int argc, char** argv) {
  registerGen(argc, argv, 1);
  std::cout << rnd.next("[TSG]{1,10000}") << std::endl;
}
