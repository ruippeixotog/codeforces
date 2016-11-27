#include <algorithm>
#include <cstdio>

#define MAXN 100000

using namespace std;

typedef long double ld;

int a[MAXN];

int main() {
  int n, n1, n2; scanf("%d %d %d\n", &n, &n1, &n2);
  for(int i = 0; i < n; i++)
    scanf("%d\n", &a[i]);

  int nSmall = min(n1, n2);
  int nLarge = max(n1, n2);
  sort(a, a + n);

  int idx = n - 1;
  ld avg = 0.0;
  for(int i = 0; i < nSmall; i++) {
    avg += nLarge * (ld) a[idx--];
  }
  for(int i = 0; i < nLarge; i++) {
    avg += nSmall * (ld) a[idx--];
  }
  avg /= n1 * (ld) n2;

  printf("%f\n", (double) avg);
  return 0;
}
