#include <algorithm>
#include <cmath>
#include <cstdio>

#define MAXN 1000

using namespace std;

typedef long double ld;

int x[MAXN];

ld centers[MAXN];

int main() {
  int n, r; scanf("%d %d\n", &n, &r);
  for(int i = 0; i < n; i++)
    scanf("%d", &x[i]);

  for(int i = 0; i < n; i++) {
    centers[i] = r;
    for(int j = 0; j < i; j++) {
      if(abs(x[i] - x[j]) > r * 2) continue;

      ld dx = (x[i] - x[j]) / 2.0;
      ld dy = sqrt(r * r - dx * dx);
      centers[i] = max(centers[i], centers[j] + 2 * dy);
    }
    printf("%.10f ", (double) centers[i]);
  }
  return 0;
}
