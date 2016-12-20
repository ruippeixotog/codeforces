#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXN 16
#define INF 1000000000

using namespace std;

int n;
char c[MAXN]; int r[MAXN], b[MAXN];

int dp[1 << MAXN][MAXN * MAXN / 2 + 1];

void calc(int st, int k, int curr, int target) {
  if(curr == target) {
    int rCards = 0, bCards = 0;
    for(int i = 0; i < n; i++) {
      if(st & (1 << i)) (c[i] == 'R' ? rCards : bCards)++;
    }

    for(int i = 0; i < n; i++) {
      if(st & (1 << i)) continue;
      int rBonus = min(rCards, r[i]), bBonus = min(bCards, b[i]);

      for(int j = rBonus; j <= n * n / 2; j++) {
        if(dp[st][j - rBonus] < 0) continue;

        dp[st | (1 << i)][j] = max(
          dp[st | (1 << i)][j],
          dp[st][j - rBonus] + bBonus);
      }
    }
    return;
  }

  if(k == n) return;
  calc(st, k + 1, curr, target);
  calc(st | (1 << k), k + 1, curr + 1, target);
}

int main() {
  scanf("%d\n", &n);

  int rSum = 0, bSum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%c %d %d\n", &c[i], &r[i], &b[i]);
    rSum += r[i]; bSum += b[i];
  }

  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for(int i = 0; i < n; i++) {
    calc(0, 0, 0, i);
  }

  int best = INF;
  for(int i = 0; i <= n * n / 2; i++) {
    if(dp[(1 << n) - 1][i] < 0) continue;

    best = min(best, n + max(
      max(0, rSum - i),
      max(0, bSum - dp[(1 << n) - 1][i])));
  }

  printf("%d\n", best);
  return 0;
}
