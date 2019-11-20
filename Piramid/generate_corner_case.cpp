#include <iostream>
#include <iomanip>
#include <vector>
#include <set>

using point = std::pair<int, int>;

std::pair<point, point> next_squares(point const& p) {
  point r1 = p, r2 = p;
  r1.first += p.first > 0 ? 1 : -1;
  r2.second += p.second > 0 ? 1 : -1;
  return {r1, r2};
}

inline int norm_square(point const& p) noexcept {
  return p.first * p.first + p.second * p.second;
}

struct compare_norm {
  inline bool operator() (point const& p, point const& q) const noexcept {
    int lp = norm_square(p), lq = norm_square(q);
    if (lp < lq) return true;
    if (lp > lq) return false;
    return p < q;
  }
};

std::vector<std::pair<point, double>> corner_cases(int max_r2) {
  std::set<point> included;
  std::set<point, compare_norm> neighbor;
  for (int x : {1, -1})
    for (int y : {1, -1})
      neighbor.emplace(x, y);
  std::vector<std::pair<point, double>> cases;
  long long r2 = 1, max_numerator = 0, max_denominator = 1, area = 0;
  while (r2 < max_r2) {
    point p = *std::begin(neighbor);
    r2 = std::max<long long>(norm_square(p), r2);
    area++;
    bool updated = false;
    if (area * max_denominator > max_numerator * r2) {
      updated = true;
      max_denominator = r2;
      max_numerator = area;
    }
    if (updated && area % 4 != 0)
      cases.emplace_back(p, static_cast<double>(area) / static_cast<double>(r2));
    neighbor.erase(std::begin(neighbor));
    auto nexts = next_squares(p);
    neighbor.insert(nexts.first);
    neighbor.insert(nexts.second);
  }
  return cases;
}

int main() {
  int r2;
  std::cin >> r2;
  auto const& cases = corner_cases(r2);
  for (auto&& p : cases)
    std::cout << '(' << p.first.first << ", " << p.first.second << ") : "
      << std::setprecision(10) << p.second << std::endl;
}

