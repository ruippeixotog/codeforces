#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstring>

#define MAXN 1000

using namespace std;

typedef long double ld;

int x[MAXN + 2], y[MAXN + 2];

ld dist(ld x0, ld y0, ld x1, ld y1) {
  return sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
}

ld distK(int i, int j, int k) {
  ld num = (y[j] - y[i]) * (ld) x[k] -
    (x[j] - x[i]) * (ld) y[k] +
    x[j] * (ld) y[i] - y[j] * (ld) x[i];

  return abs(num) / dist(x[i], y[i], x[j], y[j]);
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d %d\n", &x[i], &y[i]);

  memcpy(x + n, x, 2 * sizeof(int));
  memcpy(y + n, y, 2 * sizeof(int));

  ld best = LDBL_MAX;
  for(int i = 1; i <= n; i++) {
    best = min(best, distK(i - 1, i + 1, i) / 2);
  }
  printf("%.9lf\n", (double) best);
  return 0;
}
