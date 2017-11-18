#include <algorithm>
#include <cstdio>
#include <map>

#define MAXN 200000
#define MAXK 200000
#define INF 2000000000

using namespace std;

int c[MAXN], v[MAXN], g[MAXK];

int dg[MAXK + 1];

int main() {
  int n, k, s, t; scanf("%d %d %d %d\n", &n, &k, &s, &t);
  for(int i = 0; i < n; i++)
    scanf("%d %d\n", &c[i], &v[i]);
  for(int i = 0; i < k; i++)
    scanf("%d\n", &g[i]);

  sort(g, g + k);

  dg[k] = s - g[k - 1];
  for(int i = k - 1; i > 0; i--) {
    dg[i] = g[i] - g[i - 1];
  }
  dg[0] = g[0];
  sort(dg, dg + k + 1);

  int neededBoost = max(s * 2 - t, 0);
  int allPotentialBoosts = 0;
  map<int, int> potentialBoosts;

  for(int i = 0; i <= k; i++) {
    int m = min(dg[i], dg[k] - dg[i]);
    neededBoost -= m;
    if(dg[i] - m > 0) {
      allPotentialBoosts++;
      potentialBoosts[dg[i] - m]++;
    }
  }

  int extra = 0;
  while(neededBoost > 0 && !potentialBoosts.empty()) {
    auto e = *potentialBoosts.begin();
    potentialBoosts.erase(e.first);

    int neededExtra = ((neededBoost - 1) / allPotentialBoosts) + 1;
    int boostLen = min(e.first - extra, neededExtra);

    neededBoost -= allPotentialBoosts * boostLen;
    allPotentialBoosts -= e.second;
    extra += boostLen;
  }

  int best = -1, bestPrice = INF;
  if(neededBoost <= 0) {
    int minTank = dg[k] + extra;
    for(int i = 0; i < n; i++) {
      if(v[i] >= minTank && c[i] < bestPrice) {
        best = i;
        bestPrice = c[i];
      }
    }
  }

  printf("%d\n", best == -1 ? -1 : bestPrice);
  return 0;
}
