#include <algorithm>
#include <cstdio>
#include <numeric>

#define MAXN 200000

using namespace std;

typedef long long ll;

ll hp[MAXN], dmg[MAXN];

int order[MAXN];

int main() {
  int n, a, b; scanf("%d %d %d\n", &n, &a, &b);
  for(int i = 0; i < n; i++)
    scanf("%lld %lld\n", &hp[i], &dmg[i]);

  iota(order, order + n, 0);
  sort(order, order + n, [](int i1, int i2) {
    return dmg[i1] - hp[i1] < dmg[i2] - hp[i2];
  });

  ll aMult = 1;
  while(a--) aMult *= 2;

  ll dmgSum = 0, aImprov = 0, penalty = 0;
  for(int i = 0; i < n; i++) {
    int idx = order[i]; ll updDmg;
    if(i < b) {
      updDmg = max(dmg[idx], hp[idx]);
      aImprov = max(aImprov, hp[idx] * aMult - updDmg);
      if(i == b - 1) {
        penalty = max(0LL, hp[idx] - dmg[idx]);
      }
    } else {
      updDmg = dmg[idx];
      if(b > 0) {
        aImprov = max(aImprov, hp[idx] * aMult - updDmg - penalty);
      }
    }
    dmgSum += updDmg;
  }
  printf("%lld\n", dmgSum + aImprov);
  return 0;
}
