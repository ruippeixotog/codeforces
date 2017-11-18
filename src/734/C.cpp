#include <algorithm>
#include <cstdio>

#define MAXM 200000
#define MAXK 200000

using namespace std;

typedef long long ll;

int a[MAXM], b[MAXM], c[MAXK], d[MAXK];

ll useType2(int s, int k) {
  int* p = upper_bound(d, d + k, s) - 1;
  return p == d - 1 ? 0 : c[p - d];
}

int main() {
  int n, m, k; scanf("%d %d %d", &n, &m, &k);
  int x, s; scanf("%d %d", &x, &s);

  for(int i = 0; i < m; i++)
    scanf("%d", &a[i]);
  for(int i = 0; i < m; i++)
    scanf("%d", &b[i]);
  for(int i = 0; i < k; i++)
    scanf("%d", &c[i]);
  for(int i = 0; i < k; i++)
    scanf("%d", &d[i]);

  ll best = (ll) x * (n - useType2(s, k));
  for(int i = 0; i < m; i++) {
    if(s >= b[i]) {
      best = min(best, (ll) a[i] * (n - useType2(s - b[i], k)));
    }
  }
  printf("%lld\n", best);
  return 0;
}
