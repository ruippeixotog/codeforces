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

#define MAXN 1000
#define MAXF 1000000000.0
#define EPS 0.000000001

using namespace std;

typedef long long ll;
typedef long double ld;

int ab[2 * MAXN];

int main() {
  int n, m; scanf("%d\n%d\n", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", &ab[i * 2]);
  for(int i = 0; i < n; i++)
    scanf("%d", &ab[i == 0 ? 2 * n - 1 : (i - 1) * 2 + 1]);

  ld lowF = 0, hiF = MAXF + 1;
  while(lowF + EPS < hiF) {
    ld midF = (lowF + hiF) / 2.0;

    ld fuelLeft = midF;
    for(int i = 0; i < 2 * n && fuelLeft >= 0; i++) {
      fuelLeft -= (m + fuelLeft) / ab[i];
    }

    if(fuelLeft >= 0) hiF = midF;
    else lowF = midF;
  }

  if(lowF > MAXF) printf("-1\n");
  else printf("%.8f\n", (double) lowF);
  return 0;
}
