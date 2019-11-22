#include "testlib/testlib.h"

int main(int argc, char** argv) {
  registerValidation(argc, argv);
  inf.readToken("[TSG]{1,10000}", "S");
  inf.readEoln();
  inf.readEof();
}
