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

#define MAXN 100000
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

int t[MAXN];

// int dp[MAXN + 1][1 + 90 + 1440];
int currDp[1 + 90 + 1440];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d\n", &t[i]);

  memset(currDp, 0x3f, sizeof(currDp));
  currDp[0] = 0;

  int paid = 0, lastT = -INF;

  for(int i = 1; i <= n; i++) {
    int nextDp[1 + 90 + 1440];
    memset(nextDp, 0x3f, sizeof(nextDp));

    int timePassed = t[i - 1] - lastT;

    int best = INF;
    int bestEmpty = currDp[0];

    for(int j = 0; j < 1440; j++) {
      if(j + timePassed < 90) {
        best = min(best, currDp[1 + j]);
        nextDp[1 + j + timePassed] = min(
          nextDp[1 + j + timePassed],
          currDp[1 + j]);
      } else {
        bestEmpty = min(bestEmpty, currDp[1 + j]);
      }

      if(j + timePassed < 1440) {
        best = min(best, currDp[1 + 90 + j]);
        nextDp[1 + 90 + j + timePassed] = min(
          nextDp[1 + 90 + j + timePassed],
          currDp[1 + 90 + j]);
      } else {
        bestEmpty = min(bestEmpty, currDp[1 + 90 + j]);
      }
    }

    nextDp[0] = bestEmpty + 20;
    nextDp[1 + 0] = bestEmpty + 50;
    nextDp[1 + 90 + 0] = bestEmpty + 120;
    best = min(best, bestEmpty + 20);

    printf("%d\n", best - paid);

    paid = best;
    lastT = t[i - 1];
    memcpy(currDp, nextDp, sizeof(currDp));
  }
  return 0;
}
