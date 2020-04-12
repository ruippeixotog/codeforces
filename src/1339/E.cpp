#include <cstdio>

typedef long long ll;

int numBits(ll n) {
  int bits = 0;
  for(; n > 0; bits++, n /= 2) {}
  return bits;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    ll n; scanf("%lld\n", &n);

    int bits = numBits(n);
    int col = (n - 1) % 3;
    int rowGroup = (bits - 1) / 2;

    n -= 1LL << (2 * rowGroup);
    ll row = n / 3;

    ll res = 0;
    if(col == 0) {
      res = (1LL << (2 * rowGroup)) + n / 3;

    } else if(col == 1) {
      ll digs[] = {0, 2, 3, 1};
      for(int b = 0; row > 0; b += 2, row /= 4) {
        res |= digs[row % 4] << b;
      }
      res += (1LL << (2 * rowGroup + 1));

    } else {
      ll digs[] = {0, 3, 1, 2};
      for(int b = 0; row > 0; b += 2, row /= 4) {
        res |= digs[row % 4] << b;
      }
      res += (3LL << (2 * rowGroup));
    }
    printf("%lld\n", res);
  }
  return 0;
}
