#include <cstdio>
#include <vector>

#define MOD 998244353

using namespace std;

typedef long long ll;

inline ll mmul(ll a, ll b) { return (a * b) % MOD; }
inline ll madd(ll a, ll b) { return (a + b) % MOD; }

ll mpow(ll a, ll p) {
  if(p == 0) return 1;
  ll halfPow = mpow(a, p / 2);
  return mmul(halfPow, p % 2 ? mmul(a, halfPow) : halfPow);
}

// modular inverse exists only if MOD is prime (or coprime to a)
ll minv(ll a) { return mpow(a, MOD - 2); }
ll mdiv(ll a, ll b) { return mmul(a, minv(b)); }

vector<ll> _mfactMem(1, 1);
ll mfact(ll a) {
  if(a >= MOD) return 0;
  while(a >= _mfactMem.size())
    _mfactMem.push_back(mmul(_mfactMem.size(), _mfactMem.back()));
  return _mfactMem[a];
}

ll mcomb(ll n, ll k) {
  if (n == 0 && k == 0) return 1;
  ll ni = n % MOD, ki = k % MOD;
  if (ni < ki) return 0;
  ll comb = mmul(mfact(ni), mmul(minv(mfact(ki)), minv(mfact(ni - ki))));
  return mcomb(n / MOD, k / MOD) * comb;
}

ll calc(int na, int nb) {
  ll cnt = 0;
  for(int i = 0; i <= min(na, nb); i++) {
    cnt = madd(cnt, mmul(mfact(i), mmul(mcomb(na, i), mcomb(nb, i))));
  }
  return cnt;
}

int main() {
  int a, b, c; scanf("%d %d %d\n", &a, &b, &c);
  int res = (int) mmul(calc(a, b), mmul(calc(b, c), calc(c, a)));
  printf("%d\n", res);
  return 0;
}
