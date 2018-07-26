#include <cstdio>

#define MAXN 1000

typedef long double ld;

int ab[2 * MAXN];

int main() {
  int n, m; scanf("%d\n%d\n", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", &ab[i * 2]);
  for(int i = 0; i < n; i++)
    scanf("%d", &ab[i == 0 ? 2 * n - 1 : (i - 1) * 2 + 1]);

  ld fuel = 0;
  for(int i = 2 * n - 1; i >= 0; i--) {
    if(ab[i] == 1) { fuel = -1; break; }
    fuel = (ab[i] * fuel + m) / (ab[i] - 1);
  }
  printf("%.9f\n", (double) fuel);
  return 0;
}
