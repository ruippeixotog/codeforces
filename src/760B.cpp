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
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

int x[MAXN], y[MAXN];

int main() {
  int n, m, k; scanf("%d %d %d\n", &n, &m, &k);

  m -= n;
  // int side = min(k - 1, n - k) - 1;

  int st = 0, end = m;
  while(st < end) {
    int mid = (st + end + 1) / 2;

    int sideLeft = min(k - 1, mid - 1);
    int sideRight = min(n - k, mid - 1);
    int minLeft = mid - sideLeft; // max(0, mid - (k - 1));
    int minRight = mid - sideRight; // max(0, mid - (n - k));

    ll needed = mid +
      sideLeft * (minLeft + (ll) (mid - 1)) / 2 +
      sideRight * (minRight + (ll) (mid - 1)) / 2;

    if(needed > m) end = mid - 1;
    else st = mid;
  }

  printf("%d\n", st + 1);
  return 0;
}
