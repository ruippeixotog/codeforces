#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 200000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int a[MAXN];

int main() {
  int n, m; scanf("%d %d\n", &n, &m);

  int res;
  int low = min(n, m), high = max(n, m);

  if(low == 1) {
    high %= 6;
    res = min(high, 6 - high);

  } else if(low == 2) {
    if(high == 2) res = 4;
    else if(high == 3 || high == 7) res = 2;
    else res = 0;

  } else {
    res = (low * (ll) high) % 2 == 0 ? 0 : 1;

//    int toRemove = low - 3;
//    ll completed =
//      toRemove * (ll) low + toRemove * (ll) high - toRemove * (ll) toRemove;
//
//    ll rem = min(completed % 6, 6 - completed % 6);
//    low -= toRemove; high -= toRemove;
  }

  printf("%lld\n", (n * (ll) m) - res);
  return 0;
}
