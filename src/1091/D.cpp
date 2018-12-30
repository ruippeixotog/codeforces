#include <cstdio>

#define MOD 998244353

typedef long long ll;

inline ll mmul(ll a, ll b) { return (a * b) % MOD; }
inline ll madd(ll a, ll b) { return (a + b) % MOD; }

ll crossMatches(ll n, int depth) {
  if(n == 1) return 0;
  return madd(mmul(n - 1, depth), mmul(n, crossMatches(n - 1, depth + 1)));
}

int main() {
  int n; scanf("%d\n", &n);

  ll res = 1;
  for(int i = 2; i <= n; i++) {
    res = mmul(res, i);
  }
  res = madd(res, crossMatches(n, 0));
  printf("%lld\n", res);
  return 0;
}
