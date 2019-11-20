#include "../testlib/testlib.h"
#include <iostream>
#include <cmath>
#include <utility>
#include <tuple>
#include <string>

std::pair<int, int> random_rational(int integer_max, double maximum, double minimum) {
  int denominator, numerator_max, numerator_min;
  do {
    denominator = rnd.next(1, integer_max);
    numerator_max = std::min<int>(integer_max, static_cast<double>(denominator) * maximum);
    numerator_min = std::ceil(static_cast<double>(denominator) * minimum);
  } while (numerator_max < numerator_min);
  int numerator = rnd.next(numerator_min, numerator_max);
  return {numerator, denominator};
}

int main(int argc, char** argv) {
  registerGen(argc, argv, 1);
  int n, d, integer_max = 1000000;
  double maximum = 3.135, minimum = 0;
  if (argc >= 2)
    minimum = std::stod(argv[1]);
  if (argc >= 3)
    maximum = std::stod(argv[2]);
  if (argc >= 4)
    integer_max = std::stoi(argv[3]);
  std::tie(n, d) = random_rational(integer_max, maximum, minimum);
  std::cout << n << ' ' << d << std::endl;
}
