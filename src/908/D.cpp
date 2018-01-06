#include <cstdio>
#include <cstring>

#define MAXK 1000
#define MOD 1000000007

using namespace std;

typedef long long ll;

inline ll mmul(ll a, ll b) { return (a * b) % MOD; }
inline ll madd(ll a, ll b) { return (a + b) % MOD; }
inline ll msub(ll a, ll b) { return (a + MOD - b) % MOD; }

ll mpow(ll a, ll p) {
  if(p == 0) return 1;
  ll halfPow = mpow(a, p / 2);
  return mmul(halfPow, p % 2 ? mmul(a, halfPow) : halfPow);
}

inline ll minv(ll a) { return mpow(a, MOD - 2); }
inline ll mdiv(ll a, ll b) { return mmul(a, minv(b)); }

int k, pa, pb;

int gsum;
ll dp[MAXK][MAXK];

ll get(int a, int ab) {
  if(a >= k - ab) return ab + a + gsum;
  if(ab >= k) return ab;
  if(dp[a][ab] == -1) {
    dp[a][ab] = madd(mmul(pa, get(a + 1, ab)), mmul(pb, get(a, ab + a)));
  }
  return dp[a][ab];
}

int main() {
  scanf("%d %d %d\n", &k, &pa, &pb);

  int sum = pa + pb;
  pa = (int) mdiv(pa, sum), pb = (int) mdiv(pb, sum);
  gsum = (int) mdiv(msub(1, pb), pb);

  memset(dp, -1, sizeof(dp));
  printf("%d\n", (int) get(1, 0));
  return 0;
}
