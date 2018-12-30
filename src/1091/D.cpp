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
#define MOD 998244353

using namespace std;

typedef long long ll;
typedef long double ld;

inline ll mmul(ll a, ll b) { return (a * b) % MOD; }
inline ll madd(ll a, ll b) { return (a + b) % MOD; }
inline ll msub(ll a, ll b) { return (a + MOD - b) % MOD; }

ll mpow(ll a, ll p) {
  if(p == 0) return 1;
  ll halfPow = mpow(a, p / 2);
  return mmul(halfPow, p % 2 ? mmul(a, halfPow) : halfPow);
}

// modular inverse exists only if MOD is prime (or coprime to a)
inline ll minv(ll a) { return mpow(a, MOD - 2); }
inline ll mdiv(ll a, ll b) { return mmul(a, minv(b)); }

vector<ll> _mfactMem(1, 1);
ll mfact(ll a) {
  if(a >= MOD) return 0;
  while(a >= _mfactMem.size())
    _mfactMem.push_back(mmul(_mfactMem.size(), _mfactMem.back()));
  return _mfactMem[a];
}

ll numMatches(ll n, int depth) {
  if(n == 1) return 0;
  return madd(mmul(n - 1, depth), mmul(n, numMatches(n - 1, depth + 1)));
}

int main() {
  int n; scanf("%d\n", &n);

  ll res = madd(mfact(n), numMatches(n, 0));
  printf("%lld\n", res);
  return 0;
}
