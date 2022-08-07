#include <algorithm>
#include <functional>
#include <cstdio>

#define MAXN 200000

using namespace std;

typedef long long ll;

int v[MAXN];

ll sum[MAXN], tMin[MAXN];

ll ceilDiv(ll a, ll b) { return (a + b - 1) / b; }

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);

  sum[n - 1] = 0;
  for(int i = n - 2; i >= 0; i--) {
    sum[i] = sum[i + 1] + v[i + 1];
  }

  ll tBase = 0, extra = 0;
  for(int i = 0; i < n; i++) {
    ll vi = v[i] - extra;
    if(vi > tBase) {
      ll tMore = ceilDiv(vi - tBase, i + 1);
      extra = tMore * (i + 1) - (vi - tBase);
      tBase += tMore;
    } else {
      extra = tBase - vi;
    }
    tMin[i] = tBase + max(0LL, ceilDiv(sum[i] - extra, i + 1));
  }

  int q; scanf("%d\n", &q);
  for(int qi = 1; qi <= q; qi++) {
    int t; scanf("%d\n", &t);

    ll* it = lower_bound(tMin, tMin + n, t, greater<ll>());
    printf("%ld\n", it == tMin + n ? -1 : it - tMin + 1);
  }
  return 0;
}
