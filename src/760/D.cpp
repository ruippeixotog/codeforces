#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXN 100000
#define INF 1000000000

using namespace std;

int t[MAXN];

int dp[1 + 90 + 1440];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d\n", &t[i]);

  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;

  int paid = 0, lastT = -INF;
  for(int i = 1; i <= n; i++) {
    int newDp[1 + 90 + 1440];
    memset(newDp, 0x3f, sizeof(newDp));

    int timePassed = t[i - 1] - lastT;
    int bestEmpty = dp[0];

    for(int j = 0; j < 90; j++) {
      if(j + timePassed < 90) {
        newDp[1 + j + timePassed] = dp[1 + j];
      } else {
        bestEmpty = min(bestEmpty, dp[1 + j]);
      }
    }

    for(int j = 0; j < 1440; j++) {
      if(j + timePassed < 1440) {
        newDp[1 + 90 + j + timePassed] = dp[1 + 90 + j];
      } else {
        bestEmpty = min(bestEmpty, dp[1 + 90 + j]);
      }
    }

    newDp[0] = bestEmpty + 20;
    newDp[1 + 0] = bestEmpty + 50;
    newDp[1 + 90 + 0] = bestEmpty + 120;

    int best = INF;
    for(int j = 0; j < 1 + 90 + 1440; j++) {
      best = min(best, newDp[j]);
    }

    printf("%d\n", best - paid);

    paid = best;
    lastT = t[i - 1];
    memcpy(dp, newDp, sizeof(dp));
  }
  return 0;
}
