#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using point = pair<int, int>;

inline int norm_square(point const& p) noexcept {
  return p.first * p.first + p.second * p.second;
}

inline bool compare_norm(point const& p, point const& q) noexcept {
    int lp = norm_square(p), lq = norm_square(q);
    if (lp < lq) return true;
    if (lp > lq) return false;
    return p < q;
}

int count_lattice(int n, int d) {
  vector<point> lattice;
  for (int x = -600; x <= 600; x++) {
    for (int y = -600; y <= 600; y++) {
      if (x == 0 || y == 0) continue;
      lattice.emplace_back(x, y);
    }
  }
  sort(begin(lattice), end(lattice), compare_norm);
  long long cells = 0;
  for (auto&& p : lattice) {
    cells++;
    long long r2 = norm_square(p);
    if (cells * d >= n * r2)
      return cells;
  }
  return -1;
}

int main() {
  int n, d;
  cin >> n >> d;
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  cout << count_lattice(n, d) << endl;
}
