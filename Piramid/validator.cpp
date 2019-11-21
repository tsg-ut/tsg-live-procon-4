#include "testlib/testlib.h"

constexpr int MaxInteger = 1000000;
constexpr long long MaxNumerator = 3135, MaxDenominator = 1000;

int main(int argc, char** argv) {
  registerValidation(argc, argv);
  long long n = inf.readInt(0, MaxInteger, "N");
  inf.readSpace();
  long long d = inf.readInt(0, MaxInteger, "D");
  ensure(n * MaxDenominator <= d * MaxNumerator);
  inf.readEoln();
  inf.readEof();
}
