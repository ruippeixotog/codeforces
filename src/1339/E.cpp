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

int numBits(ll n) {
  int bits = 0;
  while(n > 0) {
    bits++;
    n /= 2;
  }
  return bits;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    ll n; scanf("%lld\n", &n);

    int bits = numBits(n);

    int col = (n - 1) % 3;
    int rowGroup = (bits - 1) / 2;

    n -= 1LL << (rowGroup * 2);
    ll row = n / 3;

    ll res = 0;
    if(col == 0) {
      res = (1LL << (2 * rowGroup)) + row;
    } else if(col == 1) {
      vector<ll> digs = {0, 2, 3, 1};
      for(int b = 0; row > 0; b += 2, row /= 4) {
        res |= digs[row % 4] << b;
      }
      res += (1LL << (2 * rowGroup + 1));
    } else {
      vector<ll> digs = {0, 3, 1, 2};
      for(int b = 0; row > 0; b += 2, row /= 4) {
        res |= digs[row % 4] << b;
      }
      res += (3LL << (2 * rowGroup));
    }
    printf("%lld\n", res);
  }
  return 0;
}
