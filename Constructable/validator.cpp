#include "testlib/testlib.h"

int main(int argc, char** argv) {
  constexpr int MaxX = 1000000000;
  constexpr int MaxAB = 1000;
  registerValidation(argc, argv);
  inf.readInt(1, MaxAB, "A");
  inf.readSpace();
  inf.readInt(1, MaxAB, "B");
  inf.readSpace();
  inf.readInt(1, MaxX, "X");
  inf.readEoln();
  inf.readEof();
}
