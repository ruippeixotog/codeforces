#include <cstdio>

typedef long long ll;

int main() {
  ll n, m, k; scanf("%lld %lld %lld\n", &n, &m, &k);
  ll row = k < n ? k : n - 1 - (k - n) / (m - 1);
  ll col = k < n ? 0 : 1 + (row % 2 ?
    (k - n) % (m - 1) : m - 2 - (k - n) % (m - 1));
  printf("%lld %lld\n", row + 1, col + 1);
  return 0;
}
