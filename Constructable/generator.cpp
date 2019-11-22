#include "testlib/testlib.h"
#include <iostream>
#include <numeric>

bool is_constructable(int a, int b, int x) {
  for (int i = 1; a * i < x; i++)
    for (int j = 1; a * i + b * j <= x; j++)
      if (a * i + b * j == x) return true;
  return false;
}

int main(int argc, char** argv) {
  constexpr int MaxX = 1000000000;
  constexpr int MaxAB = 1000;
  registerGen(argc, argv, 1);
  bool possible = rnd.next(0, 1);
  int a = rnd.next(1, MaxAB),
      b = rnd.next(1, MaxAB),
      g = std::gcd(a, b),
      x;
  if (possible) {
    int max_coeff = MaxX / g;
    bool large = rnd.next(0, 1);
    if (a * b <= max_coeff && large) {
      x = g * rnd.next(a * b, max_coeff);
    }
    else {
      max_coeff = std::min(max_coeff, a * b - 1);
      do {
        x = g * rnd.next(1, max_coeff);
      } while (!is_constructable(a, b, x));
    }
  }
  else {
    bool gcd_issue = rnd.next(1, 3) == 1;
    if (g != 1 && gcd_issue) {
      do {
        x = rnd.next(a * b, MaxX);
      } while (x % g == 0);
    }
    else {
      do {
        x = rnd.next(1, a * b - 1);
      } while (is_constructable(a, b, x));
    }
  }
  std::cout << a << ' ' << b << ' ' << x << std::endl;
}
