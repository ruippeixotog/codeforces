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

#define MAXN 300000
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef long double ld;

inline ll madd(ll a, ll b) { return (a + b) % MOD; }
inline ll mmul(ll a, ll b) { return (a * b) % MOD; }

ll mpow(ll a, ll p) {
  if(p == 0) return 1;
  ll halfPow = mpow(a, p / 2);
  return mmul(halfPow, p % 2 ? mmul(a, halfPow) : halfPow);
}

int x[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &x[i]);

  sort(x, x + n);
  ll dist = 0;
  for(int i = 1; i < n; i++)
    dist += x[i] - x[i - 1];

  ll mult = dist % MOD, sum = 0;
  for(int i = 0; i < n / 2; i++) {
    cerr << "dist: " << dist << endl;

    sum = madd(sum, mmul(mult, mpow(2, i)));
    if(i < n - i - 2) {
      sum = madd(sum, mmul(mult, mpow(2, n - i - 2)));
    }
    dist -= (x[i + 1] - x[i]);
    dist -= (x[n - i - 1] - x[n - i - 2]);
    mult = madd(mult, dist);
  }
  printf("%d\n", (int) sum);
  return 0;
}
